#ifndef INCLUDE_CHANNELIZER_H
#define INCLUDE_CHANNELIZER_H

#include <dsp/basebandsamplesink.h>
#include <list>
#include <QMutex>
#include "util/export.h"
#include "util/message.h"

class MessageQueue;
class IntHalfbandFilter;

class SDRANGEL_API DownChannelizer : public BasebandSampleSink {
	Q_OBJECT
public:
	class SDRANGEL_API MsgChannelizerNotification : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		MsgChannelizerNotification(int samplerate, qint64 frequencyOffset) :
			Message(),
			m_sampleRate(samplerate),
			m_frequencyOffset(frequencyOffset)
		{ }

		int getSampleRate() const { return m_sampleRate; }
		qint64 getFrequencyOffset() const { return m_frequencyOffset; }

	private:
		int m_sampleRate;
		qint64 m_frequencyOffset;
	};

	DownChannelizer(BasebandSampleSink* sampleSink);
	virtual ~DownChannelizer();

	void configure(MessageQueue* messageQueue, int sampleRate, int centerFrequency);
	int getInputSampleRate() const { return m_inputSampleRate; }

	virtual void start();
	virtual void stop();
	virtual void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool positiveOnly);
	virtual bool handleMessage(const Message& cmd);

protected:
	struct FilterStage {
		enum Mode {
			ModeCenter,
			ModeLowerHalf,
			ModeUpperHalf
		};

		typedef bool (IntHalfbandFilter::*WorkFunction)(Sample* s);
		IntHalfbandFilter* m_filter;
		WorkFunction m_workFunction;

		FilterStage(Mode mode);
		~FilterStage();

		bool work(Sample* sample)
		{
			return (m_filter->*m_workFunction)(sample);
		}
	};
	typedef std::list<FilterStage*> FilterStages;
	FilterStages m_filterStages;
	BasebandSampleSink* m_sampleSink;
	int m_inputSampleRate;
	int m_requestedOutputSampleRate;
	int m_requestedCenterFrequency;
	int m_currentOutputSampleRate;
	int m_currentCenterFrequency;
	SampleVector m_sampleBuffer;
	QMutex m_mutex;

	void applyConfiguration();
	bool signalContainsChannel(Real sigStart, Real sigEnd, Real chanStart, Real chanEnd) const;
	Real createFilterChain(Real sigStart, Real sigEnd, Real chanStart, Real chanEnd);
	void freeFilterChain();

signals:
	void inputSampleRateChanged();
};

#endif // INCLUDE_CHANNELIZER_H