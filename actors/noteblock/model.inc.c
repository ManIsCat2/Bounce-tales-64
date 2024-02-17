Lights1 noteblock_f3dlite_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx noteblock__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 noteblock__0_rgba16[] = {
	#include "actors/noteblock/_0.rgba16.inc.c"
};

Vtx noteblock_000_offset_mesh_layer_1_vtx_0[22] = {
	{{ {177, -174, -177}, 0, {178, 621}, {73, 183, 183, 255} }},
	{{ {-177, -174, 177}, 0, {235, 563}, {183, 183, 73, 255} }},
	{{ {-177, -174, -177}, 0, {235, 621}, {183, 183, 183, 255} }},
	{{ {177, -174, 177}, 0, {178, 563}, {73, 183, 73, 255} }},
	{{ {177, -174, -177}, 0, {1022, -16}, {73, 183, 183, 255} }},
	{{ {177, 174, 177}, 0, {-16, 1008}, {73, 73, 73, 255} }},
	{{ {177, -174, 177}, 0, {-16, -16}, {73, 183, 73, 255} }},
	{{ {177, 174, -177}, 0, {1022, 1008}, {73, 73, 183, 255} }},
	{{ {177, -174, -177}, 0, {-1054, -16}, {73, 183, 183, 255} }},
	{{ {-177, 174, -177}, 0, {-16, 1008}, {183, 73, 183, 255} }},
	{{ {177, 174, -177}, 0, {-1054, 1008}, {73, 73, 183, 255} }},
	{{ {-177, -174, -177}, 0, {-16, -16}, {183, 183, 183, 255} }},
	{{ {177, 174, 177}, 0, {1022, 1008}, {73, 73, 73, 255} }},
	{{ {-177, -174, 177}, 0, {-16, -16}, {183, 183, 73, 255} }},
	{{ {177, -174, 177}, 0, {1022, -16}, {73, 183, 73, 255} }},
	{{ {-177, 174, 177}, 0, {-16, 1008}, {183, 73, 73, 255} }},
	{{ {-177, 174, -177}, 0, {-1054, 1008}, {183, 73, 183, 255} }},
	{{ {-177, -174, -177}, 0, {-1054, -16}, {183, 183, 183, 255} }},
	{{ {-177, 174, -177}, 0, {235, 621}, {183, 73, 183, 255} }},
	{{ {177, 174, 177}, 0, {292, 563}, {73, 73, 73, 255} }},
	{{ {177, 174, -177}, 0, {292, 621}, {73, 73, 183, 255} }},
	{{ {-177, 174, 177}, 0, {235, 563}, {183, 73, 73, 255} }},
};

Gfx noteblock_000_offset_mesh_layer_1_tri_0[] = {
	gsSPVertex(noteblock_000_offset_mesh_layer_1_vtx_0 + 0, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 5, 4, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 8, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 13, 12, 15, 0),
	gsSP2Triangles(16, 13, 15, 0, 13, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 19, 18, 21, 0),
	gsSPEndDisplayList(),
};


Gfx mat_noteblock_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(noteblock_f3dlite_material_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, noteblock__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx noteblock_000_offset_mesh_layer_1[] = {
	gsSPDisplayList(mat_noteblock_f3dlite_material),
	gsSPDisplayList(noteblock_000_offset_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

