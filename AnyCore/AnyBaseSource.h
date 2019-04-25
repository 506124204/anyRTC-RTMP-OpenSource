#pragma once
#include "LIV_Export.h"
#include <string>
#include <cstdint>
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
	// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
	// type �������͡�
	// timestamp ʱ���
	// data ���ݻ���
	// size ���ݻ����С��
	virtual int Read(char* type, uint32_t* timestamp, char** data, int* size) = 0; 
};

