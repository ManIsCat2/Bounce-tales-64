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

hook_event(HOOK_UPDATE, override_char)