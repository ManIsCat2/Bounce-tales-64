-- name: Bounce Tales 64
-- description: 
-- incompatible: romhack

gLevelValues.entryLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.coinsRequiredForCoinStar = 30

camera_set_use_course_specific_settings(false)

E_MODEL_ALOXADO = smlua_model_util_get_id("aloxado_geo")

--smlua_audio_utils_replace_sequence(0x02, 17, 75, "0x02 - aw(n17)")

function override_char()
    gNetworkPlayers[0].overrideModelIndex = 0
end

function before_set_mario_action(m, act)
    if act == ACT_PUNCHING or act == ACT_MOVE_PUNCHING or act == ACT_JUMP_KICK or act == ACT_DIVE then
        return 1
    end
end
hook_event(HOOK_UPDATE, override_char)
hook_event(HOOK_BEFORE_SET_MARIO_ACTION, before_set_mario_action)