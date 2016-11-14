///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef _SDRPLAY_SDRPLAYSETTINGS_H_
#define _SDRPLAY_SDRPLAYSETTINGS_H_

#include <stdint.h>
#include <QByteArray>

struct SDRPlaySettings {
	typedef enum {
		FC_POS_INFRA = 0,
		FC_POS_SUPRA,
		FC_POS_CENTER
	} fcPos_t;

	uint64_t m_centerFrequency;
	int32_t  m_LOppmTenths;
    uint32_t m_frequencyBandIndex;
    uint32_t m_ifFrequencyIndex;
    uint32_t m_mirDcCorrIndex;
    uint32_t m_mirDcCorrTrackTimeIndex;
    uint32_t m_bandwidthIndex;
	uint32_t m_devSampleRateIndex;
	uint32_t m_gainRedctionIndex;
	uint32_t m_log2Decim;
	fcPos_t m_fcPos;
	bool m_dcBlock;
	bool m_iqCorrection;

	SDRPlaySettings();
	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
};

#endif /* _SDRPLAY_SDRPLAYSETTINGS_H_ */