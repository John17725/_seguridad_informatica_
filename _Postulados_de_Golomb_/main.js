const prompt = require("prompt-sync")();
const colors = require('colors/safe')
var regex = new RegExp("^[0-1]{1,}$");
var cant_0 = 0;
var cant_1 = 0;
var diferencia = 0;
var option;
var contador_1 = 0;
var racha_1 = 0;
var racha_2 = 0;
var racha_3 = 0;
var racha_4 = 0;
var racha_5 = 0;

function generateBinaryByString (value) {
	// const value = prompt("Ingrese su palabra  de 8 caracteres: ");
	const textToBinary = (value = '') => {
		let res = ' ';
		res = value.split('').map(char => {
			return char.charCodeAt(0).toString(2);

		}).join('0');
		return '0'+res;
	};
	console.log("\n\n")
	console.log('\t [',value,'] ==> [ ',textToBinary(value)," ]");
	console.log("\n\n")
}

function inserInputValueBit(){
	let palabra = prompt("Ingrese la cadena de bits: ");
	return palabra;
}

function inserInputValueString(){
	let palabra = prompt("Ingrese la palabra a convertir en bits: ");
	return palabra;
}

function validateInputMenu(value){
	let regex = new RegExp("^[0-4]+$");
	if (!regex.test(value)) {
		console.log("\tIngrese solo un numero del 1 al 4")
	}
}

function validateInputString(value){
	let regex_two = new RegExp("^[A-Za-z]+$")
	if (!regex_two.test(value)) {
		return false;
	}else {
		console.log("Ok ✅");
		return true
	}
}

function validateInputBits(value){
	if (!regex.test(value)) {
		return false;
	}else {
		console.log("Ok ✅");
		return true;
	}
}


function mainFunction () {
	do{
		cant_0 = 0;
		cant_1 = 0;
		diferencia = 0;
		racha_1 = 0;
		racha_2 = 0;
		racha_3 = 0;
		racha_4 = 0;
		racha_5 = 0;
		console.log("=== 1. Generar bits");
		console.log("=== 2. Comprobacion de Postulado 1");
		console.log("=== 3. Comprobacion de Posutlado 2");
		console.log("=== 4. Salir de programa");
		option = prompt("==> ")

		validateInputMenu(option);

		switch (option) {
			case '1':{
				let inputPalabra = inserInputValueString();
				while (!validateInputString(inputPalabra)) {
					console.log("\n\tEl input tiene propiedades incumplidas, ingrese nuevamente una palabra",colors.red("solo letras"));
					inputPalabra = inserInputValueString();
				}
				generateBinaryByString(inputPalabra);
				break;
			}
			case '2':{
				console.log("\n\n")
				let palabra = inserInputValueBit();
				while (!validateInputBits(palabra)) {
					console.log("\n\tEl input tiene propiedades incumplidas, ingrese nuevamente la cadena de bits");
					palabra = inserInputValueBit();
				}
				var arr = palabra.split('');
				console.log('Input ==> [',palabra,']\nNumero de bits ==> ',arr.length)
				for (var i = 0; i <= arr.length; i++) {
					if (arr[i] == 0) {
						cant_0 ++;
					}
					else if (arr[i] == 1) {
						cant_1 ++;
					}
				}
				console.log("Cantidad de 0 en la cadena ==> ",cant_0,"\nCantidad de 1 en la cadena ==> ",cant_1);
				if (cant_1 >= cant_0 || cant_0 >= cant_1) {
					diferencia = cant_1 - cant_0;
					diferencia = Math.abs(diferencia);
					if (diferencia > 1) {
						console.log("La diferencia es mayor a 1,", colors.red("por lo que el postulado 1 no se cumple, diferencia ==> "),diferencia);
					}else if(diferencia >= 0 && diferencia < 2){
						console.log("La diferencia es de ==> ",diferencia, colors.green("Por lo que el postulado 1 Si se cumple"));
					}
				}
				console.log("\n\n")
				break;
			}
			case '3':{
				console.log("\n\n")
				let palabra = inserInputValueBit();
				while (!validateInputBits(palabra)) {
					console.log("\n\tEl input tiene propiedades incumplidas, ingrese nuevamente la cadena de bits");
					palabra = inserInputValueBit();
				}
				let arr_palabra = palabra.split('');
				for (var i = 0; i <= arr_palabra.length-1; i++) {
					if (arr_palabra[i] != arr_palabra[i+1]) {
						contador_1++;
						if (contador_1 == 1) {
							process.stdout.write(" ")
							process.stdout.write(colors.red(arr_palabra[i]))
							racha_1++;
						}else if (contador_1 == 2) {
							process.stdout.write(" ")
							process.stdout.write(colors.blue(arr_palabra[i-1]))
							process.stdout.write(colors.blue(arr_palabra[i]))
							racha_2++;
						}else if (contador_1 == 3) {
							process.stdout.write(" ")
							process.stdout.write(colors.yellow(arr_palabra[i-2]))
							process.stdout.write(colors.yellow(arr_palabra[i-1]))
							process.stdout.write(colors.yellow(arr_palabra[i]))
							racha_3++;
						}else if(contador_1 == 4){
							process.stdout.write(" ")
							process.stdout.write(colors.cyan(arr_palabra[i-3]))
							process.stdout.write(colors.cyan(arr_palabra[i-2]))
							process.stdout.write(colors.cyan(arr_palabra[i-1]))
							process.stdout.write(colors.cyan(arr_palabra[i]))
							racha_4++;
						}else if(contador_1 == 5){
							process.stdout.write(" ")
							process.stdout.write(colors.gray(arr_palabra[i-4]))
							process.stdout.write(colors.gray(arr_palabra[i-3]))
							process.stdout.write(colors.gray(arr_palabra[i-2]))
							process.stdout.write(colors.gray(arr_palabra[i-1]))
							process.stdout.write(colors.gray(arr_palabra[i]))
							racha_5++;
						}
						contador_1 = 0;
					}else {
						contador_1++;
					}
				}
				console.log("\n")
				let total_rachas = racha_1+racha_2+racha_3+racha_4;
				console.log("\tTotal de rachas obtenidas ==>",total_rachas);
				if (total_rachas%2 == 0) {
					let aux_2;
					let auxTotalRachas;
					auxTotalRachas  = Math.round(total_rachas/2);
					if (racha_1 == auxTotalRachas) {
						console.log("Numero de rachas de 1 ==> ",racha_1,colors.green("Por lo que cumple el postulado G1"))
					}else {
						aux_2 = auxTotalRachas - racha_1;
						aux_2 = Math.abs(aux_2);
						console.log("Numero de rachas de 1 ==> ",racha_1,"La diferencia de la mitad es de [",aux_2,"]",colors.red("Por lo que no cumple el postulado G1"))
					}
					aux_2 = 0;
					auxTotalRachas = 0;
					auxTotalRachas  = Math.round(total_rachas/4);
					if (racha_2 == auxTotalRachas) {
						console.log("Numero de rachas de 2 ==> ",racha_2,colors.green("Por lo que cumple el postulado G2"))
					}else {
						aux_2 = auxTotalRachas - racha_2;
						aux_2 = Math.abs(aux_2);
						console.log("Numero de rachas de 2 ==> ",racha_2,"La diferencia de la mitad es de [",aux_2,"]",colors.red("Por lo que no cumple el postulado G2"))
					}
					aux_2 = 0;
					auxTotalRachas = 0;
					auxTotalRachas  = Math.round(total_rachas/8);
					if (racha_3 == auxTotalRachas) {
						console.log("Numero de rachas de 3 ==> ",racha_3,colors.green("Por lo que cumple el postulado G3"))
					}else {
						aux_2 = auxTotalRachas - racha_3;
						aux_2 = Math.abs(aux_2);
						console.log("Numero de rachas de 3 ==> ",racha_3,"La diferencia de la mitad es de [",aux_2,"]",colors.red("Por lo que no cumple el postulado G3"))
					}
					aux_2 = 0;
					auxTotalRachas = 0;
					auxTotalRachas  = Math.round(total_rachas/16);
					if (racha_4 == auxTotalRachas) {
						console.log("Numero de rachas de 4 ==> ",racha_4,colors.green("Por lo que cumple el postulado G4"))
					}else {
						aux_2 = auxTotalRachas - racha_4;
						aux_2 = Math.abs(aux_2);
						console.log("Numero de rachas de 4 ==> ",racha_4,"La diferencia de la mitad es de [",aux_2,"]",colors.red("Por lo que no cumple el postulado G4"))
					}
					aux_2 = 0;
					auxTotalRachas = 0;
				}else {
					// console.log("es impar")
					let newTotalRachas;
					newTotalRachas  = Math.round(total_rachas/2);
					let aux;
					aux = newTotalRachas - racha_1;
					aux = Math.abs(aux);
					if (aux > 1 ) {
						console.log("Numero de rachas de 1 ==> ",racha_1,"La diferencia de la mitad es de [",aux,"]",colors.red("Por lo que no cumple el postulado G1"))
					}else {
						console.log("Numero de rachas de 1 ==> ",racha_1,"La diferencia de la mitad es de [",aux,"]",colors.green("Por lo que cumple el postulado G1"))
					}
					aux = 0;
					newTotalRachas  = Math.round(total_rachas/4);
					aux = newTotalRachas - racha_2;
					aux = Math.abs(aux);
					if (aux > 1 ) {
						console.log("Numero de rachas de 2 ==> ",racha_2,"La diferencia de la mitad es de [",aux,"]",colors.red("Por lo que no cumple el postulado G2"))
					}else {
						console.log("Numero de rachas de 2 ==> ",racha_2,"La diferencia de la mitad es de [",aux,"]",colors.green("Por lo que cumple el postulado G2"))
					}
					aux = 0;
					newTotalRachas  = Math.round(total_rachas/8);
					aux = newTotalRachas - racha_3;
					aux = Math.abs(aux);
					if (aux > 1 ) {
						console.log("Numero de rachas de 3 ==> ",racha_3,"La diferencia de la mitad es de [",aux,"]",colors.red("Por lo que no cumple el postulado G3"))
					}else {
						console.log("Numero de rachas de 3 ==> ",racha_3,"La diferencia de la mitad es de [",aux,"]",colors.green("Por lo que cumple el postulado G3"))
					}
					aux = 0;
					newTotalRachas  = Math.round(total_rachas/16);
					aux = newTotalRachas - racha_4;
					aux = Math.abs(aux);
					if (aux > 1 ) {
						console.log("Numero de rachas de 4 ==> ",racha_4,"La diferencia de la mitad es de [",aux,"]",colors.red("Por lo que no cumple el postulado G4"))
					}else {
						console.log("Numero de rachas de 4 ==> ",racha_4,"La diferencia de la mitad es de [",aux,"]",colors.green("Por lo que cumple el postulado G4"))
					}
					aux = 0;
					newTotalRachas = 0;
				}
				break;
			}
			case '4':
				console.log("Saliendo del programa.....")
				break;
			default:
				console.log('\tOpcion no valida, ingrese una opcion valida')
				break;
		}
	} while (option != 4);
}

mainFunction();