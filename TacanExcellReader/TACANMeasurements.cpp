#include "TacanMeasurements.h"

using namespace std;
using namespace Enums;

uint64_t Types::COPY_CONSTRUCTOR_INVOKE_COUNT = 0U;

Types::TacanMeasurement::TacanMeasurement(const TacanMeasurement& other)
    : id(other.id),
    time(other.time),
    channel(other.channel),
    TRV(other.TRV),
    TBV(other.TBV),
    TRR(other.TRR),
    BIV(other.BIV),
    TBE(other.TBE),
    TRE(other.TRE),
    status(other.status),
    beacon_id_1(other.beacon_id_1),
    beacond_id_2(other.beacond_id_2),
    beacon_id_3(other.beacon_id_3),
    range(other.range),
    bearing(other.bearing),
    range_error(other.range_error),
    bearing_error(other.bearing_error),
    range_rate(other.range_rate)
{
    Types::COPY_CONSTRUCTOR_INVOKE_COUNT += 1;
    std::cout << "TacanMeasurement copy constructor invoked.\n";
}

Types::TacanMeasurement::TacanMeasurement()
    :   id(0U),
        time(std::string{""}),
        channel(std::string{""}),
        TRV(Validty::NotValid),
        TBV(Validty::NotValid),
        TRR(Validty::NotValid),
        BIV(Validty::NotValid),
        TBE(Extrapolation::NotExtrapolated),
        TRE(Extrapolation::NotExtrapolated),
        status(Status::Ignore),
        beacon_id_1(char{'\0'}),
        beacond_id_2(char{ '\0' }),
        beacon_id_3(char{ '\0' }),
        range(0.00f),
        bearing(0.00f),
        range_error(0.00F),
        bearing_error(0.00F),
        range_rate(0U)
{
    std::cout << "TacanMeasurement default constructor invoked.\n";
}
uint64_t Utils::get_sample_count(const std::vector<Types::TacanMeasurement>& measurements)
{
	return measurements.size();
}

std::tuple<uint32_t, uint32_t> Utils::count_extrapolations(const std::vector<Types::TacanMeasurement>& measurements)
{
	uint32_t range_extrapolation_counter{ 0U };

	uint32_t bearing_extrapolation_counter{ 0U };

	for (auto const& measurement : measurements)
	{
		if (measurement.TRE == Enums::Extrapolation::Extrapolated) {
			range_extrapolation_counter += 1;
			}

		if (measurement.TBE == Enums::Extrapolation::Extrapolated) {
			bearing_extrapolation_counter += 1;
			}
	}

	return std::make_tuple(range_extrapolation_counter, bearing_extrapolation_counter);

}

