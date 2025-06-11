#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include "Enums.h"

using namespace std;

namespace Types {

	extern uint64_t COPY_CONSTRUCTOR_INVOKE_COUNT;

	struct TacanMeasurement {
			uint8_t id;
			std::string time;
			std::string channel;
			
			//TRV,TBV,TRR,BIV Status of captured sample from device
			Enums::Validty TRV;
			Enums::Validty TBV;
			Enums::Validty TRR;
			Enums::Validty BIV;		
			Enums::Extrapolation TBE;
			Enums::Extrapolation TRE;
			Enums::Status status; 

			//Measurement properties
			char beacon_id_1, beacond_id_2, beacon_id_3;		
			float range, bearing;
			float range_error, bearing_error;
			uint32_t range_rate;

            TacanMeasurement();

            TacanMeasurement(
                uint8_t id,
                std::string time,
                std::string channel,
                Enums::Validty TRV,
                Enums::Validty TBV,
                Enums::Validty TRR,
                Enums::Validty BIV,
                Enums::Extrapolation TBE,
                Enums::Extrapolation TRE,
                Enums::Status status,
                char beacon_id_1,
                char beacon_id_2,
                char beacon_id_3,
                float range,
                float bearing,
                float range_error,
                float bearing_error,
                uint32_t range_rate
            ) :
                id(id), time(std::move(time)), channel(std::move(channel)),
                TRV(TRV), TBV(TBV), TRR(TRR), BIV(BIV),
                TBE(TBE), TRE(TRE), status(status),
                beacon_id_1(beacon_id_1), beacond_id_2(beacon_id_2), beacon_id_3(beacon_id_3),
                range(range), bearing(bearing),
                range_error(range_error), bearing_error(bearing_error),
                range_rate(range_rate)
            {}

			TacanMeasurement(const TacanMeasurement& other);
		};
}

namespace Utils {

	uint64_t get_sample_count(const std::vector< Types::TacanMeasurement>& measurements);

	std::tuple<uint32_t,uint32_t> count_extrapolations(const std::vector< Types::TacanMeasurement>& measurements);

}


