#include "Debug.h"

void(__cdecl *Debug::Log)(const char *pFormat, ...) = (void(__cdecl *)(const char *pFormat, ...))0x4068E0;

void Debug::INIParseFailed(const char* section, const char* flag, const char* value, const char* Message) {
	const char* LogMessage = (Message == nullptr)
		? "Failed to parse INI file content: [%s]%s=%s\n"
		: "Failed to parse INI file content: [%s]%s=%s (%s)\n"
		;

	Debug::Log(LogMessage, section, flag, value, Message);
}
