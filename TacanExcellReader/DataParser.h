#include "TACANMeasurements.h"
#include <xlnt/xlnt.hpp>
using namespace std;

namespace Parser {

	class DataParser {

	public:
		std::string main_path;
		explicit DataParser(std::string& file_path);
		void load_table_efficient();
		void load_table_inefficient();
		void add_measurement_inefficient(const xlnt::cell& cell);
		void add_measurement_efficient(const xlnt::cell& cell);


	private:
		xlnt::workbook wb;
		std::vector<Types::TacanMeasurement> samples; // Ensure Types is defined
		uint32_t number_of_rows{ 0U };
		uint32_t number_of_cols{ 0U };
		uint32_t number_of_data{ 0U };
	};

}