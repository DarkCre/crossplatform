﻿#include "OutputAndMmodification.h"
#include "WorkingWithFiles.h"
#include "WorkingWithGraph.h"
#include "Creature.h"

//Функциональная часть консоли
int MainSharedConsole(unordered_map<int, Pipe>& MapP, unordered_map<int, Cs>& MapCs, forward_list<int>& FreePipes, unordered_map<int, pair <int, int>>& Graph)
{
	int item = IntInput(0, 7);

	switch (item)
	{
		case 1:
		{
			CreatingPipe(MapP, FreePipes);
			PauseAndClearing();
			return true;
		}
		case 2:
			CreatingObject(MapCs);
			PauseAndClearing();
			return true;
		case 3:
			InformationOutput(MapP,MapCs);
			return true;
		case 4:
			ChangingObjects(MapP, MapCs, Graph,FreePipes);
			PauseAndClearing();
			return true;
		case 5:
			OutputInFile(MapP, MapCs, FreePipes, Graph);
			PauseAndClearing();
			return true;
		case 6:
			ReadingFromFile(MapP, MapCs, FreePipes, Graph);
			PauseAndClearing();
			return true;
		case 7:
			WorkingWithGraph(MapP, MapCs, FreePipes, Graph);
			return true;
		case 0:
			cout << endl << "Вы хотите сохранить текущее состояние?" <<
				endl << "Введите 1 для сохранения или 0, для выхода из программы." << endl;
			if (EnteringCheckingBool()) { OutputInFile(MapP, MapCs, FreePipes, Graph);}
			return false;
	}
	
	return true;
}

//Точка входа в программу
int main() 
{
	setlocale(LC_ALL, "rus"); //Подключение руссофикатора
	unordered_map<int, Pipe> MapP;
	unordered_map<int, Cs> MapCs;
	forward_list<int> FreePipes;

	unordered_map<int, pair <int, int>> Graph;

	//Запуск консоли
	do { 
		cout << endl;
		cout << " Главное меню: " << endl
			<< "1. Добавить трубу" << endl
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Изменение объектов" << endl
			<< "5. Сохранить" << endl
			<< "6. Загрузить" << endl
			<< "7. Работа с графом" << endl
			<< "0. Выход" << endl << endl;
	} while (MainSharedConsole(MapP,MapCs, FreePipes, Graph) != 0);
}