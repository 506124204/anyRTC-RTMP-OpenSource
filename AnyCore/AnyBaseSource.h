#pragma once
#include "LIV_Export.h"
#include <string>
#include <cstdint>

// https://blog.csdn.net/sz76211822/article/details/53760836
struct FLV_HEADER {
	uint8_t btSignature[3];
	uint8_t btVersion;
	uint8_t btFlags;
	uint8_t btDataOffset[4];
	FLV_HEADER() {
		memset(this, 0, sizeof(FLV_HEADER));
	}
};

struct TAG_HEADER {
	uint8_t btPreviousTagSize[4];
	uint8_t btTagType;
	uint8_t btDataSize[3];
	uint8_t btTimeStamp[3];
	uint8_t btReserved;
	uint8_t btStreamID[3];
	TAG_HEADER() {
		memset(this, 0, sizeof(TAG_HEADER));
	}
};

class LIV_API  AnyBaseSource
{
public:
	AnyBaseSource();
	virtual ~AnyBaseSource();
public:
	virtual int Create(std::string url) = 0; // ��rtmpЭ�齨������Դ�ӿڡ�������ʵԴ�������ļ���rtmp,rtsp,�ȵ���֪�ļ���Э�顣
	virtual int Disconnect() = 0;	// �Ͽ�����
	virtual int Handshake() = 0;	// ����Э�顣
	virtual int Connectapp() = 0;	// ֪ͨ����Դ����app��live/livestream����(rtmp://www.pic98.com/live/livestream)
	virtual int Playstream() = 0;	// ֪ͨ����Դ��ʼ��ȡ���ݡ�
	virtual int Clear() = 0;
	virtual bool onMetaData(char type, char* data, int size) = 0;
	virtual bool NeedSlowdown() { return false; }
	virtual uint32_t SeekTo(uint32_t,double) = 0;
	// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
	// type �������͡�
	// timestamp ʱ���
	// data ���ݻ���
	// size ���ݻ����С��
	virtual int Read(char* type, uint32_t* timestamp, char** data, int* size, TAG_HEADER& tag) = 0;
	virtual double GetPropDouble(const char* key) = 0;
};

