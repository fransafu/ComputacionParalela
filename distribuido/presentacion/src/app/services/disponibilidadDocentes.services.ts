import { Injectable } from '@angular/core';
import { Http, Response, Headers, RequestOptions } from '@angular/http';
import 'rxjs/add/operator/map';
import { Observable } from 'rxjs/Observable';

@Injectable()
export class DisponibilidadDocentesServices{
	public url: string;

	constructor(private _http:Http){
		//this.url = "http://localhost:3030/disponibilidad_docentes/";
		this.url = "http://localhost:3030/disponibilidad_docentes/";
		//this.url = "http://localhost:8000/api/ramos-1";
	}

	getDisponibilidadDocentes(){
		return this._http.get(this.url)
						 .map(res => res.json());
	}

	getEjecutar(){
		return this._http.get("http://localhost:3030/acceso/1")
						 .map(res => res.json());
	}

	postActualizarDisponibilidad( disponibilidad:string ){

		// let token = "dad4b93de77a08b38850b7befcf7ed4753e84542";

	   let body = disponibilidad;
	   /*{'docente_id':'5',
	    							'rut':'6.443.706-2',
	    							'disponibilidad':[
	    								{'dia':'MARTES','periodo':'2'},
	    								{'dia':'MIERCOLES','periodo':'2'},
	    								{'dia':'JUEVES','periodo':'2'},
	    								{'dia':'MARTES','periodo':'3'},
	    								{'dia':'MIERCOLES','periodo':'3'},
	    								{'dia':'JUEVES','periodo':'3'},
	    								{'dia':'MARTES','periodo':'4'},
	    								{'dia':'MIERCOLES','periodo':'4'},
	    								{'dia':'JUEVES','periodo':'4'},
	    								{'dia':'MARTES','periodo':'5'},
	    								{'dia':'MIERCOLES','periodo':'5'},
	    								{'dia':'JUEVES','periodo':'5'}
	    							]} */
	    //						);// disponibilidad; //JSON.stringify( disponibilidad );
	    						
	    /*
	    let body = {"username":"admin",
					"password":"paralela890"};
	    let headers = new Headers({
	      'Content-Type':'application/json'//,
	      //'Authorization' : token
	    });

	    return this._http.post( "http://localhost:8000/rest-auth/login/", JSON.stringify(body), headers )
	        .map( res=>{
	          console.log(res);
	          return res.json();
	        })
	        */

		//let body = JSON.stringify({ 'username': 'admin',
		// 							'password': 'paralela890' });
		// let body = JSON.stringify({ "sala": { "nombre": "M1-203", "capacidad": "3" }});
		let headers = new Headers({ 'Content-Type': 'application/json' });
		let options = new RequestOptions({ headers: headers });
		console.log(body);
		return this._http.post( this.url, body, options )
	        .map( res=>{
	          console.log(res);
	          res.json();
	        });

	}

}
