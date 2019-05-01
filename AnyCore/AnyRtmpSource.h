#pragma once
#include "LIV_Export.h"
#include "AnyBaseSource.h"


class LIV_API AnyRtmpSource :
	public AnyBaseSource
{
public:
	AnyRtmpSource();
	virtual ~AnyRtmpSource();
public:
	virtual int Create(std::string url) ; // ��rtmpЭ�齨������Դ�ӿڡ�������ʵԴ�������ļ���rtmp,rtsp,�ȵ���֪�ļ���Э�顣
	virtual int Disconnect() ;	// �Ͽ�����
	virtual int Handshake() ;	// ����Э�顣
	virtual int Connectapp() ;	// ֪ͨ����Դ����app��live/livestream����(rtmp://www.pic98.com/live/livestream)
	virtual int Playstream() ;	// ֪ͨ����Դ��ʼ��ȡ���ݡ�
	virtual uint32_t SeekTo(uint32_t, double) { return 0; };
	// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
	// type �������͡�
	// timestamp ʱ���
	// data ���ݻ���
	// size ���ݻ����С��
	virtual int Read(char* type, uint32_t* timestamp, char** data, int* size, TAG_HEADER& tag) ;
	virtual int Clear();
	virtual bool onMetaData(char type, char* data, int size);
	virtual double GetPropDouble(const char* key) { return 0.0f; };
protected:
	void* rtmp_;
};

