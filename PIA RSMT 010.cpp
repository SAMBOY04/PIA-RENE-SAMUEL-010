#include <iostream>

#include <fstream>

#include <string>




using namespace std;



bool VALP(string entradap) //Valida el precio

{

	bool ValP = true;

	int TamTXTP = entradap.length();



	for (int p = 0; p < TamTXTP; p++)

	{

		if (entradap[p] <= 47 || entradap[p] >= 58)

		{

			ValP = false;

			break;

		}

	}

	return ValP;

};



bool VALCODD(string entrada) //valida el codigo

{

	bool Val = true;

	int TamTXT = entrada.size();

	if (TamTXT != 4) {

		Val = false;

	}

	for (int j = 0; j < TamTXT; j++)

	{

		if (entrada[j] <= 47 || entrada[j] >= 58)

		{

			Val = false;

			break;

		}

	}

	return Val;

};



struct {

	string NOMBRE, GEN, CODIGO, PRECIO;

}Ordenes[30];

int e, O = 0;

int main()

{

	int ui, eli;;



	string NOMD, GENERO, CODD, PRECIO;

	while (true) {



		system("cls");

		printf("		Bienvenido a GameStop \n Seleccione una opcion?\n");

		printf( " 1] Agregar Videojuego \n");

		printf( " 2] Ver Videojuego\n");

		printf( " 3] Borrar Videojuego\n");
        
		printf( " 4] Salir\n");

		printf( "Opcion a tomar:\n ");

		cin >> ui;

		switch (ui)

		{

		case 1:

			system("cls");

			printf( "Ingrese el codigo del videojuego\n");

			cin >> CODD;

			while (!VALCODD(CODD)) {

				printf( "Porfavor ingrese 4 valores numericos\n");

				cin >> CODD;

			}

			Ordenes[O].CODIGO = CODD;

			printf( "Nombre del videojuego \n");

			cin.ignore();

			getline(cin, NOMD);

			Ordenes[O].NOMBRE = NOMD;

			printf( "Genero del videojuego 1)Aventura 2)Carreras 3)Luchas 4)Rol \n");

			cin >> e;

			switch (e) {

			case 1: GENERO = "Aventura";

				break;

			case 2: GENERO = "CARRERAS";

				break;

			case 3: GENERO = "LUCHAS";

				break;

			case 4: GENERO = "ROL";

				break;
		     

			default: cout << "Ingrese un numero entre 1 y 4." << endl;

				cin.clear();

				cin.ignore();

				cin >> e;

				break;

			}

			Ordenes[O].GEN = GENERO;



			printf( "Precio\n");

			cin >> PRECIO;

			while (!VALP(PRECIO)) {

				printf("Porfavor ingrese solo valores numericos\n");

				cin >> PRECIO;

			}

			Ordenes[O].PRECIO = PRECIO;

			O = O + 1;

			break;

		case 2:

			system("cls");

			if (O == 0) {

				printf( "Aun no hay ordenes activas.\n");

				system("pause");

				break;

			}

			for (int i = 0; i < O; i++) {

				printf("Numero de orden: ") i + 1 << endl;

				printf("Nombre del videojuego: ") << Ordenes[i].NOMBRE << endl;

				printf("Genero: ") << Ordenes[i].GEN << endl;

				printf("Precio: ") << Ordenes[i].PRECIO << endl << endl;

				printf("Total: ") << Ordenes[i].PRECIO << endl << endl;

				printf("==========================================" << endl;

			}

			system("pause");

			break;

		case 3:

			system("cls");

			if (O == 0) {

				printf("Aun no hay ordenes activas.\n");

				system("pause");

				break;

			}

			printf("Ingrese el numero de orden a eliminar.\n");

			for (int i = 0; i < O; i++) {

				cout << "Numero de orden: " << i + 1 << endl;

				cout << "Nombre del videojuego: " << Ordenes[i].NOMBRE << endl;

				cout << "Genero: " << Ordenes[i].GEN << endl;

				cout << "Precio: " << Ordenes[i].PRECIO << endl << endl;

				cout << "Total: " << Ordenes[i].PRECIO << endl << endl;

				printf("==========================================\n");

			}

			cin >> eli;

			for (int i = eli - 1; i < O; i++) 
			{

				Ordenes[i].CODIGO = Ordenes[i + 1].CODIGO;

				Ordenes[i].GEN = Ordenes[i + 1].GEN;

				Ordenes[i].NOMBRE = Ordenes[i + 1].NOMBRE;

				Ordenes[i].PRECIO = Ordenes[i + 1].PRECIO;

				Ordenes[i + 1].CODIGO = "0";



			}

			O = O - 1;

			break;
		

			

        case 4:

			system("cls");

			cout << "Guardando la informacion en un archivo." << endl; //Esto generara el archivo de texto.

			for (int i = 0; i < O; i++) {



				ofstream Os("Ordenes.txt", ios::app);

				if (!Os)

				{

					cout << "Error opening file" << endl;

				}

				Os << endl << "Codigo: " << Ordenes[i].CODIGO << endl << "Nombre: " << Ordenes[i].NOMBRE << endl << "Precio: " << Ordenes[i].PRECIO << endl << "Genero: " << Ordenes[i].GEN << endl;

				;

			}

			system("pause");

			exit(0);

			break;

		}

	}

	return 0;

}