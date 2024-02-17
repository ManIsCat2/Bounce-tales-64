#include "src/game/envfx_snow.h"

const GeoLayout mario_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 150, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
			    GEO_ASM(0, geo_mario_set_player_colors),
				GEO_ASM(0, geo_mirror_mario_backface_culling),
				GEO_ASM(0, geo_mirror_mario_set_alpha),
				GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
									GEO_OPEN_NODE(),
										GEO_ASM(0, geo_move_mario_part_from_parent),
										GEO_ASM(0, geo_mario_tilt_torso),
										GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 68, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 87, 0, 0, NULL),
												GEO_OPEN_NODE(),
													GEO_ASM(0, geo_mario_head_rotation),
													GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
													GEO_OPEN_NODE(),
														GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
														GEO_OPEN_NODE(),
															GEO_NODE_START(),
															GEO_OPEN_NODE(),
																GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
																GEO_OPEN_NODE(),
																	GEO_NODE_START(),
																	GEO_OPEN_NODE(),
																		GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_000_displaylist_mesh_layer_1),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, -126, 15, -33, -133),
														GEO_OPEN_NODE(),
															GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
															GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
															GEO_OPEN_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
														GEO_TRANSLATE_ROTATE(LAYER_FORCE, 142, -51, 126, -15, 33, -133),
														GEO_OPEN_NODE(),
															GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
															GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
															GEO_OPEN_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 67, -10, 79, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, NULL),
														GEO_OPEN_NODE(),
															GEO_SWITCH_CASE(1, geo_switch_mario_hand),
															GEO_OPEN_NODE(),
																GEO_NODE_START(),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
																	GEO_OPEN_NODE(),
																		GEO_ASM(1, geo_mario_hand_foot_scaler),
																		GEO_SCALE(LAYER_FORCE, 65536),
																		GEO_OPEN_NODE(),
																		GEO_CLOSE_NODE(),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 68, -10, -79, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
													GEO_OPEN_NODE(),
														GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, NULL),
														GEO_OPEN_NODE(),
															GEO_SWITCH_CASE(0, geo_switch_mario_hand),
															GEO_OPEN_NODE(),
																GEO_NODE_START(),
																GEO_OPEN_NODE(),
																	GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
																	GEO_OPEN_NODE(),
																		GEO_ASM(0, geo_mario_hand_foot_scaler),
																		GEO_SCALE(LAYER_FORCE, 65536),
																		GEO_OPEN_NODE(),
																		GEO_CLOSE_NODE(),
																		GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
																	GEO_CLOSE_NODE(),
																GEO_CLOSE_NODE(),
															GEO_CLOSE_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, 42, NULL),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 67, 0, 0, NULL),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, -42, NULL),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
											GEO_OPEN_NODE(),
												GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, NULL),
												GEO_OPEN_NODE(),
													GEO_ANIMATED_PART(LAYER_OPAQUE, 67, 0, 0, NULL),
													GEO_OPEN_NODE(),
														GEO_ASM(2, geo_mario_hand_foot_scaler),
														GEO_SCALE(LAYER_FORCE, 65536),
														GEO_OPEN_NODE(),
														GEO_CLOSE_NODE(),
													GEO_CLOSE_NODE(),
												GEO_CLOSE_NODE(),
											GEO_CLOSE_NODE(),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ASM(1, geo_mirror_mario_backface_culling),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};