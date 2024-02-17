--------------------------
-----Helper Functions-----
--------------------------

---@param param any
---@param case_table table
---@return function | nil
local function switch(param, case_table)
    local case = case_table[param]
    if case then return case() end
    local def = case_table['default']
    return def and def() or nil
end

--- Moves Mario to the top of the object, then sets his Y speed and resets his fall.
---@param m MarioState
---@param obj Object
---@param vel_y integer
local function bounce_off_object(m, obj, vel_y)
    m.pos.y = obj.oPosY + obj.hitboxHeight
    m.vel.y = vel_y

    -- MARIO_UNKNOWN_8 is the flag that controls Mario's screaming when he falls from a high place
    -- This removes the flag so he can scream again
    m.flags = m.flags & ~MARIO_UNKNOWN_08

    play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m.marioObj.header.gfx.cameraToObject)
end

--- Gets closer to a goal value by the increment when ran
---@param goal integer
---@param src integer
---@param inc integer
local function approach_by_increment(goal, src, inc)
    local diff = goal - src
    if diff > inc then
        return src + inc
    elseif diff < -inc then
        return src - inc
    else
        return goal
    end
end

---@param obj Object
---@param obj_encompassed Object
---@param rectangle_size number
---@return boolean
local function obj_is_object_in_encompassing_rectangle(obj, obj_encompassed, rectangle_size)
    if obj_encompassed.oPosX - rectangle_size < obj.oPosX and
       obj_encompassed.oPosX + rectangle_size > obj.oPosX and
       obj_encompassed.oPosY - rectangle_size < obj.oPosY and
       obj_encompassed.oPosY + rectangle_size > obj.oPosY and
       obj_encompassed.oPosZ - rectangle_size < obj.oPosZ and
       obj_encompassed.oPosZ + rectangle_size > obj.oPosZ then
        return true
    end
    return false
end

---@param m MarioState
---@return boolean
local function is_bubbled(m)
    return m.action == ACT_BUBBLED
end

---@param parent Object
---@param model ModelExtendedId
---@param behaviorId BehaviorId
local function spawn_object_attached_to_parent(parent, model, behaviorId)
    local obj = spawn_non_sync_object(behaviorId, model, 0, 0, 0, nil)
    if not obj then return nil end

    obj_copy_pos_and_angle(obj, parent)
    return obj
end

---@return boolean
local function is_current_area_sync_valid()
    local np = gNetworkPlayers
    for i = 0, MAX_PLAYERS - 1, 1 do
        if np[i] and np[i].connected and (not np[i].currLevelSyncValid or not np[i].currAreaSyncValid) then
            return false
        end
    end
    return true
end

-- ! Neither of these convert functions have floating-point numbers in mind

---@param num number
---@return number
local function convert_s16(num)
    num = num & 0xFFFF
    return ((num >= 0x7FFF) and (num - 0x10000) or num)
end

---@param num number
---@return number
local function convert_s32(num)
    num = num & 0xFFFFFFFF
    return ((num >= 0x7FFFFFFF) and (num - 0x100000000) or num)
end

---@param start_point number
---@param end_point number
---@param time number
---@return number
local function lerp(start_point, end_point, time)
    return start_point * (1 - time) + end_point * time
end

---@param obj Object
local function object_drop_to_floor(obj)
    local x = obj.oPosX
    local y = obj.oPosY
    local z = obj.oPosZ

    local floorHeight = find_floor_height(x, y + 200, z)
    obj.oPosY = floorHeight
    obj.oMoveFlags = (obj.oMoveFlags | OBJ_MOVE_ON_GROUND)
end

---@param parent Object
---@param modelId integer | ModelExtendedId
---@param bhvId integer | BehaviorId
---@param x number
---@param y number
---@param z number
---@param rx number
---@param ry number
---@param rz number
---@return Object | nil
local function spawn_object_abs_with_rot(parent, uselessArg, modelId, bhvId, x, y, z, rx, ry, rz)
    local childObj = spawn_non_sync_object(bhvId, modelId, 0, 0, 0, nil);
    if not childObj then
        return nil
    end

    childObj.parentObj = parent
    childObj.header.gfx.areaIndex = parent.header.gfx.areaIndex
    childObj.header.gfx.activeAreaIndex = parent.header.gfx.areaIndex
    childObj.globalPlayerIndex = 0

    obj_set_pos(childObj, x, y, z);
    obj_set_angle(childObj, rx, ry, rz);

    return childObj
end

---@param obj Object
---@param model ModelExtendedId | integer
---@param id_behToSpawn BehaviorId
---@param minSpawnDist number
local function create_respawner(obj, model, id_behToSpawn, minSpawnDist)
    local respawner = spawn_object_abs_with_rot(obj, 0, E_MODEL_NONE, id_bhvRespawner, obj.oHomeX, obj.oHomeY, obj.oHomeZ, 0, 0, 0)
    respawner.oBehParams = obj.oBehParams
    respawner.oRespawnerModelToRespawn = model
    respawner.oRespawnerMinSpawnDist = minSpawnDist
    respawner.oRespawnerBehaviorToRespawn = get_behavior_from_id(id_behToSpawn)
end

local string_pack = string.pack
local string_unpack = string.unpack
---@param value number
---@param pack_fmt string
---@param unpack_fmt string
local repack = function (value, pack_fmt, unpack_fmt)
    return string_unpack(unpack_fmt, string_pack(pack_fmt, value))
end



NOTEBLOCK_ACT_IDLE = 0
NOTEBLOCK_ACT_BOUNCE = 1

COL_NOTEBLOCK_MOP = smlua_collision_util_get("col_Noteblock_MOP_0xaa6444")

MODEL_NOTEBLOCK = smlua_model_util_get_id("noteblock_geo")

---@param m MarioState
---@return boolean
local function is_bubbled(m)
    return m.action == ACT_BUBBLED
end


---@param obj Object
function bhv_noteblock_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_NOTEBLOCK_MOP
    obj.oHomeX = obj.oPosX
    obj.oHomeY = obj.oPosY
    obj.oHomeZ = obj.oPosZ

    -- I guess it's slightly larger than intended
    cur_obj_scale(0.64)
end

---@param obj Object
function bhv_noteblock_loop(obj)
    obj_set_model_extended(obj, MODEL_NOTEBLOCK)

    load_object_collision_model()

    local m = gMarioStates[0]
    local y_spd = 64

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
         --this is awful -- It really is -Sunk
        -- Jump. If A is pressed during the jump, increase y_spd.
        if m.controller.buttonPressed & A_BUTTON ~= 0 then
            y_spd = y_spd + 12
            spawn_mist_particles()
        end
        set_mario_action(m, ACT_DOUBLE_JUMP, 0)

        -- Calculates y speed
        calc_speed = repack(y_spd, "f", "I")
		calc_speed = calc_speed + (obj.oBehParams2ndByte << 16)
		y_spd = repack(calc_speed, "I", "f")
		m.vel.y = y_spd

        obj.oAction = NOTEBLOCK_ACT_BOUNCE
        -- do_fall_damage = true
    end

    if obj.oAction == NOTEBLOCK_ACT_BOUNCE then
        if obj.oTimer == 4 then
            obj.oAction = NOTEBLOCK_ACT_IDLE
            obj.oPosY = obj.oHomeY
        else
            -- Moves the noteblock slightly up and down, to give it a "bounce"
            if obj.oTimer > 2 then
                obj.oPosY = obj.oHomeY + (obj.oTimer % 3) * 6
            else
                obj.oPosY = obj.oHomeY - obj.oTimer * 6
            end
        end
    end
end

bhvNoteblock_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, bhv_noteblock_init, bhv_noteblock_loop, "bhvNoteblock_MOP")