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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470),
	LOAD_MODEL_FROM_GEO(MODEL_HMC_RED_GRILLS, hmc_geo_000530),


	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(10, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(11, 9, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(12, 9, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(13, 9, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(14, 9, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(240, 16, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(0, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, 9, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(6, 9, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 322, 2554, 8652, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(E_MODEL_RED_COIN, 322, 826, 9568, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 1057, 3716, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 1290, -3159, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 292, -9338, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 826, 9568, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 1057, 3716, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 1290, -3159, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_RED_COIN, 322, 292, -9338, 0, 0, 0, 0, id_bhvRedCoin),
		OBJECT(E_MODEL_NONE, 322, 608, -8934, 0, 0, 0,  (1 << 24), id_bhvBowserCourseRedCoinStar),
		OBJECT(E_MODEL_NONE, 322, 1890, 7973, 0, 180, 0,  (241 << 16), id_bhvDeathWarp),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 2347, 9546, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 2280, 8523, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(MODEL_NOTEBLOCK, 322, 828, 8623, 0, 0, 0, 0, bhvNoteblock_MOP),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1320, 8605, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_NONE, 322, 1502, 7716, 0, 0, 0, 0, id_bhvCoinFormation),
		OBJECT(E_MODEL_NONE, 322, 626, 5923, 0, 0, 0, 0, id_bhvCoinFormation),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 691, 5078, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 872, 4657, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1487, 4285, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1442, 3865, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1809, 4352, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_PURPLE_SWITCH, 322, 1782, 4529, 0, 0, 0, 0, id_bhvFloorSwitchGrills),
		OBJECT(0, 322, 1043, 2549, 0, 0, 0, 0, id_bhvOpenableGrill),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1010, 1878, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_NONE, 322, 489, 236, 0, 0, 0, 0, id_bhvCoinFormation),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 840, -2419, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 1080, -2774, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_GOOMBA, 322, 763, -4542, 0, 0, 0, (1 << 16), id_bhvGoomba),
		OBJECT(E_MODEL_NONE, 322, 350, -6303, 0, 0, 0, 0, id_bhvCoinFormation),
		OBJECT(E_MODEL_YELLOW_COIN, 322, 108, -7772, 0, 0, 0, 0, id_bhvYellowCoin),
		OBJECT(E_MODEL_STAR, 322, 619, -8422, 0, 0, 0, 0, id_bhvStar),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 322, 2554, 8652),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
