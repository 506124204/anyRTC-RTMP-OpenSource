#include "srs_librtmp.h"
#include "AnyRtmpSource.h"



AnyRtmpSource::AnyRtmpSource()
{
}

AnyRtmpSource::~AnyRtmpSource()
{

}

int AnyRtmpSource::Create(std::string url) {
	rtmp_ = srs_rtmp_create(url.c_str());
	return rtmp_ == NULL ? 0:1;
}

int AnyRtmpSource::Clear() {
	if (rtmp_) {
		srs_rtmp_destroy(rtmp_);
		rtmp_ = NULL;
	}
	return 0;
}

int AnyRtmpSource::Disconnect() {
	if (rtmp_) {
		srs_rtmp_disconnect_server(rtmp_);
	}
	return 0;
}

int AnyRtmpSource::Handshake() {
	if(rtmp_)
		return srs_rtmp_handshake(rtmp_);
	return 0;
}

int AnyRtmpSource::Connectapp() {
	if (rtmp_)
		return srs_rtmp_connect_app(rtmp_);
	return 0;
}

int AnyRtmpSource::Playstream() {
	if (rtmp_) {

		return srs_rtmp_play_stream(rtmp_);
	}
	return 0;
}

// ��ȡ���ݽӿڡ�����ȫ������rtmpЭ�顣
// type �������͡�
// timestamp ʱ���
// data ���ݻ���
// size ���ݻ����С��
int AnyRtmpSource::Read(char* type, uint32_t* timestamp, char** data, int* size, TAG_HEADER& tag) {
	if (rtmp_)
		return srs_rtmp_read_packet(rtmp_, type, timestamp, data, size);
	return 0;
}

bool AnyRtmpSource::onMetaData(char type, char* data, int size) {
	return srs_rtmp_is_onMetaData(type, data, size);
}