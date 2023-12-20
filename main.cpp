#include "MedicineRecord.h"
#include "MedicineRecordChild.h"

int main() 
{
    try
    {
        setlocale(LC_ALL, "ru");
        MedicineRecordChild record("Витамин D3", 13, "Принимать после еды!");
        //record.setExplanation("Принимать после еды 3 раза в день");
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

        MedicineRecord record2(record, true);

        record2.takeMedicine(MedicineRecord::AFTERNOON);

        if (record2.takeMedicineAt(MedicineRecord::DAY))
        {
            cout << endl << "Нужно принять лекарство в это время." << endl;
        }
        else
        {
            cout << endl << "Не нужно принять лекарство в это время." << endl;
        }
        record2[MedicineRecord::MIDDAY];
        record2[MedicineRecord::NIGHT];

        cout << endl << "Демонстрация работы констурктора копирования." << endl << record2;
        if (record2.planMatchesActual())
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
