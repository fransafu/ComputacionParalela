import { Injectable } from '@angular/core';
import { Http, Response, Headers, RequestOptions } from '@angular/http';
import 'rxjs/add/operator/map';
import { Observable } from 'rxjs/Observable';

@Injectable()
export class SalasServices {
	public url: string;

	constructor(private _http:Http){
		this.url = "http://localhost:3030/salas";
	}

	guardarSala( nombreSala:string, capacidadSala:string, tipoSala:string ){
		let nombre = nombreSala;
		let capacidad = capacidadSala;
		let tipo = tipoSala;

		let body = JSON.stringify({ "sala" : { "nombre": nombre,
		 							"capacidad": capacidad,
		 							"tipo": tipo }
		 							});

		let headers = new Headers({ 'Content-Type': 'application/json' });
		let options = new RequestOptions({ headers: headers });
		console.log(body);
		return this._http.post( this.url, body, options )
	        .map( res=>{
	          console.log(res);
	          res.json();
	        });
	}

	getSalas(){
		return this._http.get(this.url)
						 .map(res => res.json());
	}

	getHorarioSalas( sala:string){
		return this._http.get("http://localhost:3030/salas/" + sala + "/horarios")
						 .map(res => res.json());
	}

}
