#include "src/game/envfx_snow.h"

const GeoLayout noteblock_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 180, 262),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 62464),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 138, 0, noteblock_000_offset_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
