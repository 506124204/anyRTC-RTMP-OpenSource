#pragma once

#include "AnyBaseSource.h"
#include <map>
#include <vector>
#include <string>
#include <list>


class AnyFlvSource :
	public AnyBaseSource{
public:
	AnyFlvSource();
	AnyFlvSource(const std::string,const std::string,int32_t );
	virtual ~AnyFlvSource();

	virtual int Create(std::string url); // ��rtmpЭ�齨������Դ�ӿڡ�������ʵԴ�������ļ���rtmp,rtsp,�ȵ���֪�ļ���Э�顣
	virtual int Disconnect();	// �Ͽ�����
	virtual int Handshake();	// ����Э�顣
	virtual int Connectapp();	// ֪ͨ����Դ����app��live/livestream����(rtmp://www.pic98.com/live/livestream)
	virtual int Playstream();	// ֪ͨ����Դ��ʼ��ȡ���ݡ�
	virtual uint32_t SeekTo(uint32_t,double);
	// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
	// type �������͡�
	// timestamp ʱ���
	// data ���ݻ���
	// size ���ݻ����С��
	virtual int Read(char* type, uint32_t* timestamp, char** data, int* size,TAG_HEADER& tag);
	virtual int Clear();
	virtual bool onMetaData(char type, char* data, int size);// { return true; };
	virtual bool NeedSlowdown() { return true; }
	virtual double GetPropDouble(const char* key) {
		double dbl = 0;
		std::map<std::string, double>::iterator iter = propdbl.find(key);
		if (iter != propdbl.end())
			dbl = iter->second;
		return dbl;
	};

private:
	std::string mfile;
	std::string mdir;
	std::vector<char> mbufv;
	int64_t mreadpos;
	int64_t mfirstreadlenmin;
	double mduration;
	char* mb;
	int32_t mencryption;
	int64_t mblen;
	uint32_t dwDataSizeLast;
	uint32_t mlasttimestamp;
	std::map<std::string, double> propdbl;
	std::map<std::string, std::string> propstr;
	std::map<std::string, bool> propbool;
};

