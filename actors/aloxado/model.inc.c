Lights1 aloxado_f3dlite_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx aloxado__0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 aloxado__0_rgba16[] = {
	#include "actors/aloxado/_0.rgba16.inc.c"
};

Vtx aloxado_000_displaylist_mesh_layer_4_vtx_0[8] = {
	{{ {-168, 0, 0}, 0, {-32, -32}, {183, 183, 73, 255} }},
	{{ {167, 336, 0}, 0, {992, 992}, {73, 73, 73, 255} }},
	{{ {-168, 336, 0}, 0, {-32, 992}, {183, 73, 73, 255} }},
	{{ {167, 0, 0}, 0, {992, -32}, {73, 183, 73, 255} }},
	{{ {167, 0, -5}, 0, {992, -32}, {73, 183, 183, 255} }},
	{{ {-168, 0, -5}, 0, {-32, -32}, {183, 183, 183, 255} }},
	{{ {-168, 336, -5}, 0, {-32, 992}, {183, 73, 183, 255} }},
	{{ {167, 336, -5}, 0, {992, 992}, {73, 73, 183, 255} }},
};

Gfx aloxado_000_displaylist_mesh_layer_4_tri_0[] = {
	gsSPVertex(aloxado_000_displaylist_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(0, 4, 3, 0, 4, 0, 5, 0),
	gsSP2Triangles(0, 6, 5, 0, 6, 0, 2, 0),
	gsSP2Triangles(1, 6, 2, 0, 6, 1, 7, 0),
	gsSP2Triangles(3, 7, 1, 0, 7, 3, 4, 0),
	gsSP2Triangles(4, 6, 7, 0, 6, 4, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_aloxado_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(aloxado_f3dlite_material_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, aloxado__0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_aloxado_f3dlite_material[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx aloxado_000_displaylist_mesh_layer_4[] = {
	gsSPDisplayList(mat_aloxado_f3dlite_material),
	gsSPDisplayList(aloxado_000_displaylist_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_aloxado_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

