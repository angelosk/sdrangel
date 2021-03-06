/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube     ---   Limitations and specifcities:       * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Stopping instance i.e. /sdrangel with DELETE method is a server only feature. It allows stopping the instance nicely.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV demodulator, Channel Analyzer, Channel Analyzer NG, LoRa demodulator, TCP source   * The content type returned is always application/json except in the following cases:     * An incorrect URL was specified: this document is returned as text/html with a status 400    --- 
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGInstanceSummaryResponse.h
 * 
 * Summarized information about this SDRangel instance
 */

#ifndef SWGInstanceSummaryResponse_H_
#define SWGInstanceSummaryResponse_H_

#include <QJsonObject>


#include "SWGDeviceSetList.h"
#include "SWGLoggingInfo.h"
#include <QString>

#include "SWGObject.h"


namespace SWGSDRangel {

class SWGInstanceSummaryResponse: public SWGObject {
public:
    SWGInstanceSummaryResponse();
    SWGInstanceSummaryResponse(QString* json);
    virtual ~SWGInstanceSummaryResponse();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGInstanceSummaryResponse* fromJson(QString &jsonString);

    QString* getVersion();
    void setVersion(QString* version);

    QString* getQtVersion();
    void setQtVersion(QString* qt_version);

    QString* getAppname();
    void setAppname(QString* appname);

    QString* getArchitecture();
    void setArchitecture(QString* architecture);

    QString* getOs();
    void setOs(QString* os);

    SWGLoggingInfo* getLogging();
    void setLogging(SWGLoggingInfo* logging);

    SWGDeviceSetList* getDevicesetlist();
    void setDevicesetlist(SWGDeviceSetList* devicesetlist);


private:
    QString* version;
    QString* qt_version;
    QString* appname;
    QString* architecture;
    QString* os;
    SWGLoggingInfo* logging;
    SWGDeviceSetList* devicesetlist;
};

}

#endif /* SWGInstanceSummaryResponse_H_ */
