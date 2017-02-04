#include "Alsa.h"
#include "Trace.h"
#include <iostream>

CLASS("AlsaS");

std::string Alsa::getVersion() {
	return SND_LIB_VERSION_STR;
}

std::vector<std::string> Alsa::getStreamTypes() {
	int val;
	std::vector<std::string> array;
	for (val = 0; val <= SND_PCM_STREAM_LAST; val++) {
		array.push_back(snd_pcm_stream_name((snd_pcm_stream_t)val));
	}
	return array;
}

std::vector<std::string> Alsa::getAccessTypes() {
	int val;
	std::vector<std::string> array;
	for (val = 0; val <= SND_PCM_ACCESS_LAST; val++) {
		array.push_back(snd_pcm_access_name((snd_pcm_access_t)val));
	}
	return array;
}

std::vector<std::string> Alsa::getFormats() {
	int val;
	std::vector<std::string> array;
	for (val = 0; val <= SND_PCM_FORMAT_LAST; val++) {
		if(snd_pcm_format_name((snd_pcm_format_t)val) != NULL) {
			array.push_back(snd_pcm_format_name((snd_pcm_format_t)val));
		}
	}
	return array;
}

std::vector<std::string> Alsa::getSubFormats() {
	int val;
	std::vector<std::string> array;
	for (val = 0; val <= SND_PCM_SUBFORMAT_LAST; val++) {
		if(snd_pcm_subformat_name((snd_pcm_subformat_t)val) != NULL) {
			array.push_back(snd_pcm_subformat_name((snd_pcm_subformat_t)val));
		}
	}
	return array;
}

std::vector<std::string> Alsa::getStates() {
	METHOD("getStates()");

	int val;
	std::vector<std::string> array;
	for (val = 0; val <= SND_PCM_STATE_LAST; val++) {
		array.push_back(snd_pcm_state_name((snd_pcm_state_t)val));
	}
	return array;
}

