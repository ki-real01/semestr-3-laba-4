#include "MedicineRecord.h"
#include "MedicineRecordChild.h"

int main() 
{
    try
    {
        setlocale(LC_ALL, "ru");
        MedicineRecordChild record("Витамин D3", 13, "Принимать после еды, не глотать!");

        record.printMedicineInfo();
        record.setPlan(MedicineRecord::MORNING);
        record.setPlan(MedicineRecord::MIDDAY);
        record.setPlan(MedicineRecord::NIGHT);

        record.takeMedicine(MedicineRecord::MORNING);
        record.takeMedicine(MedicineRecord::MIDDAY);
        record.takeMedicine(MedicineRecord::NIGHT);

        cout << endl << "Значения: " << endl << record;
        if (record.planMatchesActual())
        {
            cout << endl << "План соответствует фактическому приему." << endl;
        }
        else
        {
            cout << endl << "План НЕ соответствует фактическому приему." << endl;
        }
    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
