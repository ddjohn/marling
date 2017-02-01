#ifndef ALSA_H
#define ALSA_H

#include <alsa/asoundlib.h>
#include <string>
#include <vector>

#define ALSA_PCM_NEW_HW_PARAMS_API

class Alsa {

public:
	Alsa(std::string device);
	~Alsa();

	bool canSyncStart();
	bool canResume();
	bool canPause();

	std::string getHandlerName();
	std::string getStateName();
	std::string getAccessName();

	void setHardwareParameters(snd_pcm_access_t access, snd_pcm_format_t format, int channels, unsigned int sampling);
	void prepare();
	void write(short* buf, int length);

	static std::string getVersion();
	static std::vector<std::string> getStreamTypes();
	static std::vector<std::string> getAccessTypes();
	static std::vector<std::string> getFormats();
	static std::vector<std::string> getSubFormats();
	static std::vector<std::string> getStates();

private:
	snd_pcm_t *handle;
	snd_pcm_hw_params_t *params;
};


#endif

