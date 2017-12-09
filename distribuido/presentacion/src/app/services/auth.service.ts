import { Injectable } from '@angular/core';
import { Http, Headers, RequestOptions, URLSearchParams  } from '@angular/http';
import { tokenNotExpired } from 'angular2-jwt';
import { Router } from '@angular/router';

import 'rxjs/add/operator/map';

@Injectable()
export class AuthService {

  constructor(private http: Http,private router: Router) { }

  login(values:Object) {
    console.log(values);
    /*
    let headers = new Headers();
    headers.append('Access-Control-Allow-Origin', '*');

    // Retornar un token

    let datos = new URLSearchParams();
    datos.append('email', email);
    datos.append('password',password);
    //let body = URLSearchParams.toString();
    this.http.post('http://localhost:8000/auth_login', datos, headers)
      .map(res=>res.json())
      .subscribe(
        data => localStorage.setItem('token', data.token),
        error => console.log(error)
      );
    */
  }

  loggedIn(){
    return tokenNotExpired();
  }

  logout(){
    localStorage.removeItem('token');
    this.router.navigateByUrl('./login');
  }
}