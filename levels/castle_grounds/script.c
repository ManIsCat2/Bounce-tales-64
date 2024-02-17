#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(1, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, 24, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, 12, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, 5, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, 28, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(240, 16, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(241, 16, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(6, 6, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(7, 6, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(8, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(9, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, 9, 1, 10, WARP_NO_CHECKPOINT),
	    WARP_NODE(11, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, 9, 1, 10, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 2, 0),
		OBJECT(MODEL_NONE, 500, -136, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(E_MODEL_CASTLE_DOOR_0_STARS, -820, -136, 1130, 0, 90, 0, 0x00000000, id_bhvDoor),
		OBJECT(E_MODEL_CASTLE_DOOR_0_STARS, -820, -136, 596, 0, 90, 0, (2 << 24), id_bhvDoor),
		OBJECT(E_MODEL_CASTLE_DOOR_0_STARS, -820, -136, 64, 0, 90, 0, (4 << 24), id_bhvDoor),
		OBJECT(E_MODEL_CASTLE_DOOR_0_STARS, -820, -136, -470, 0, 90, 0, (6 << 24), id_bhvDoor),
		OBJECT(E_MODEL_CASTLE_DOOR_0_STARS, -820, -136, -1002, 0, 90, 0, (8 << 24), id_bhvDoor),
		OBJECT(E_MODEL_NONE, -1575, 274, 1124, 0, 0, 0, (1 << 16), id_bhvWarp),
		OBJECT(E_MODEL_NONE, -1575, 274, 589, 0, 0, 0, (2 << 16), id_bhvWarp),
		OBJECT(E_MODEL_NONE, -1575, 274, 54, 0, 0, 0, (3 << 16), id_bhvWarp),
		OBJECT(E_MODEL_NONE, -1575, 274, -481, 0, 0, 0, (4 << 16), id_bhvWarp),
		OBJECT(E_MODEL_NONE, -1575, 274, -1016, 0, 0, 0, (5 << 16), id_bhvWarp),
		OBJECT(E_MODEL_NONE, 0, -200, 50, 0, 90, 0, (240 << 16), id_bhvDeathWarp),
		OBJECT(E_MODEL_NONE, 0, -200, 50, 0, 90, 0, (241 << 16), id_bhvAirborneStarCollectWarp),
		OBJECT(E_MODEL_ALOXADO, 186, -136, 1300, 0, 180, 0, 0x00000000, id_bhvBobombBuddy),
		OBJECT(E_MODEL_WOODEN_SIGNPOST, 501, -136, 1266, 0, 180, 0, (1 << 16), id_bhvMessagePanel),
		OBJECT(E_MODEL_WOODEN_SIGNPOST, -197, -136, 1248, 0, 180, 0, (8 << 16), id_bhvMessagePanel),
		OBJECT(E_MODEL_WOODEN_SIGNPOST, -465, -136, 1248, 0, 180, 0, (15 << 16), id_bhvMessagePanel),
		OBJECT(E_MODEL_WOODEN_SIGNPOST, 727, -136, 1266, 0, 180, 0, (15 << 16), id_bhvMessagePanel),
		OBJECT(E_MODEL_CASTLE_KEY_DOOR, -434, -136, -1306, 0, 180, 0, (2 << 24) | (6 << 16), id_bhvDoorWarp),
		OBJECT(E_MODEL_CASTLE_KEY_DOOR, -581, -136, -1306, 0, 0, 0, (2 << 24) | (6 << 16), id_bhvDoorWarp),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x02),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 2, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
