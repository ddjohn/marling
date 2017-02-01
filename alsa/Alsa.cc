#include "Alsa.h"
#include "Trace.h"
#include <iostream>

CLASS("Alsa");

void CHECK(int rc) {
	if(rc < 0)
		EXCEPTION(snd_strerror(rc));
}

Alsa::Alsa(std::string device, int type) {
	METHOD("Alsa()");
	CHECK(snd_pcm_open(&handle, device.c_str(), (snd_pcm_stream_t)type, 0)); 
	CHECK(snd_pcm_hw_params_malloc(&params));
	CHECK(snd_pcm_hw_params_any(handle, params));
}

Alsa::~Alsa() {
	METHOD("Alsa()");
	snd_pcm_drain(handle);
	snd_pcm_close(handle);
	snd_config_update_free_global();
}

void Alsa::setHardwareParameters(snd_pcm_access_t access, snd_pcm_format_t format, int channels, unsigned int sampling) {
	METHOD("setHardwareParameters(snd_pcm_access_t, snd_pcm_format_t, int, unsigned int)");

	int dir;
	CHECK(snd_pcm_hw_params_set_access(handle, params, access));
	CHECK(snd_pcm_hw_params_set_format(handle, params, format));
	CHECK(snd_pcm_hw_params_set_channels(handle, params, channels));
	CHECK(snd_pcm_hw_params_set_rate_near(handle, params, &sampling, &dir));
	CHECK(snd_pcm_hw_params(handle, params));

	//snd_pcm_hw_params_free(params));
}

void Alsa::prepare() {
	METHOD("prepare()");
	CHECK(snd_pcm_prepare(handle));	
}

void Alsa::write(short* buf, int length) {
	METHOD("write(short[], int)");
	CHECK(snd_pcm_writei(handle, buf, length));	
}

void Alsa::read(short* buf, int length) {
	METHOD("read(short[], int)");
	CHECK(snd_pcm_readi(handle, buf, length));	
}

bool Alsa::canSyncStart() {
	METHOD("canSyncStart()");
	return snd_pcm_hw_params_can_sync_start(params);
}

bool Alsa::canResume() {
	METHOD("canResume()");
	return snd_pcm_hw_params_can_resume(params);
}

bool Alsa::canPause() {
	METHOD("canPause()");
	return snd_pcm_hw_params_can_pause(params);
}

std::string Alsa::getHandlerName() {
	METHOD("getHandlerName()");
	return snd_pcm_name(handle);
}

std::string Alsa::getStateName() {
	METHOD("getStateName()");
	return snd_pcm_state_name(snd_pcm_state(handle));
}

std::string Alsa::getAccessName() {
	METHOD("getAccessName()");
	snd_pcm_access_t val;
	snd_pcm_hw_params_get_access(params, &val);
        return snd_pcm_access_name(val);
}
