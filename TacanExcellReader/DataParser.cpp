#include "DataParser.h"
#include <chrono>

using namespace Parser;

DataParser::DataParser(std::string& file_path) :  main_path(file_path)
{  
    try 
    {
        wb.load(file_path);
        std::cout << "Dosya basariyla yuklendi.\n";   
        load_table_efficient();
        //load_table_inefficient();
    }

    catch (const std::exception& ex) 
    {
        std::cerr << "Dosya yuklenemedi: " << ex.what() << "\n";
    }
}

void DataParser::load_table_efficient() 
{

    xlnt::worksheet ws = wb.active_sheet();

    this->number_of_cols = ws.highest_column().index + 1;
    this->number_of_rows = ws.highest_row();

    //std::vector kullanýrken memory reserve eden yukleyeceðimiz sample kadar memory reserve eden kod
    samples.reserve(50 * this->number_of_rows);

    //Start timer for performance measurement
    auto start = std::chrono::high_resolution_clock::now();

    uint32_t rowCount = 0;
    for (const auto& row : ws.rows())
    {
        ++rowCount;

        for (const auto& cell : row)
        {
            add_measurement_efficient(cell);
            //add_measurement_inefficient(cell);
        }

        std::cout << "Sample id:" << rowCount << " loaded !\n";

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "All samples are loaded --> copied count: " << Types::COPY_CONSTRUCTOR_INVOKE_COUNT << "\n";
    std::cout << "Efficient code --> Execution time: " << duration.count() << " ms\n";

}

void DataParser::load_table_inefficient()
{
    xlnt::worksheet ws = this->wb.active_sheet();
    this->number_of_cols = ws.highest_column().index + 1;
    this->number_of_rows = ws.highest_row();

    //Memory reserve etmeden std::vector containerina ekleme yapan kod
    //samples.reserve(50 * this->number_of_rows);

    //Start timer for performance measurement
    auto start = std::chrono::high_resolution_clock::now();

    uint32_t rowCount = 0;
    for (const auto& row : ws.rows())
    {
        ++rowCount;
        for (const auto& cell : row)
        {
            add_measurement_inefficient(cell);
            //add_measurement_inefficient(cell);
        }

        std::cout << "Sample id:" << rowCount << " loaded !\n";

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "All samples are loaded --> copied count: " << Types::COPY_CONSTRUCTOR_INVOKE_COUNT << "\n";
    std::cout << "Inefficient code -> Execution time: " << duration.count() << " ms\n";

}



void DataParser::add_measurement_inefficient(const xlnt::cell& cell)
{
    //Gereksiz copy ve default constructor çaðrýsý yapan method performansý cok düsük !!!

    Types::TacanMeasurement dummy_measurement;

    dummy_measurement.id = 1;
    dummy_measurement.time = "2025-06-11T12:00:00Z";
    dummy_measurement.channel = "X10";

    dummy_measurement.TRV = Enums::Validty::Valid;
    dummy_measurement.TBV = Enums::Validty::Valid;
    dummy_measurement.TRR = Enums::Validty::NotValid;
    dummy_measurement.BIV = Enums::Validty::Valid;
    dummy_measurement.TBE = Enums::Extrapolation::NotExtrapolated;
    dummy_measurement.TRE = Enums::Extrapolation::Extrapolated;
    dummy_measurement.status = Enums::Status::Pass;

    dummy_measurement.beacon_id_1 = 'A';
    dummy_measurement.beacond_id_2 = 'B';
    dummy_measurement.beacon_id_3 = 'C';

    dummy_measurement.range = 42.5f;
    dummy_measurement.bearing = 270.0f;
    dummy_measurement.range_error = 0.3f;
    dummy_measurement.bearing_error = 0.5f;
    dummy_measurement.range_rate = 120;    
    
    this->samples.push_back(dummy_measurement);
    
}

void DataParser::add_measurement_efficient(const xlnt::cell& cell)
{
    this->samples.emplace_back
    (
        1,
        "2025-06-11T12:00:00Z",
        "X10",
        Enums::Validty::Valid,
        Enums::Validty::Valid,
        Enums::Validty::NotValid,
        Enums::Validty::Valid,
        Enums::Extrapolation::NotExtrapolated,
        Enums::Extrapolation::Extrapolated,
        Enums::Status::Pass,
        'A', 'B', 'C',
        42.5f,
        270.0f,
        0.3f,
        0.5f,
        120
    );
}
