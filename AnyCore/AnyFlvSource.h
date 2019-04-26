#pragma once
#include "AnyBaseSource.h"
class AnyFlvSource :
	public AnyBaseSource
{
public:
	AnyFlvSource();
	AnyFlvSource(const std::string);
	virtual ~AnyFlvSource();

	virtual int Create(std::string url); // ��rtmpЭ�齨������Դ�ӿڡ�������ʵԴ�������ļ���rtmp,rtsp,�ȵ���֪�ļ���Э�顣
	virtual int Disconnect();	// �Ͽ�����
	virtual int Handshake();	// ����Э�顣
	virtual int Connectapp();	// ֪ͨ����Դ����app��live/livestream����(rtmp://www.pic98.com/live/livestream)
	virtual int Playstream();	// ֪ͨ����Դ��ʼ��ȡ���ݡ�
	// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
	// type �������͡�
	// timestamp ʱ���
	// data ���ݻ���
	// size ���ݻ����С��
	virtual int Read(char* type, uint32_t* timestamp, char** data, int* size);
	virtual int Clear();

private:
	std::string mfile;
	int64_t mreaded;
	char* mbuf,*mbufcur;
	int64_t mbuftotallen;
	int64_t mbufleftlen;
	
};

