import { Injectable } from '@angular/core';
import { Http, Response, Headers, RequestOptions } from '@angular/http';
import 'rxjs/add/operator/map';
import { Observable } from 'rxjs/Observable';

@Injectable()
export class DisponibilidadSalasServices {
	public url: string;

	constructor(private _http:Http){
		this.url = "http://localhost:3030/disponibilidad";
	}

	getDisponibilidadSalas(){
		return this._http.get(this.url)
						 .map(res => res.json());
	}

	postActualizarDisponibilidad( disponibilidad:string ){

    let body = disponibilidad;
    let headers = new Headers({
      'Content-Type':'application/json'
    });


    return this._http.post( this.url, body, { headers } )
        .map( res=>{
          return res.json();
        })
  	}


}
