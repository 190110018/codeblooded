import { Component, OnInit } from '@angular/core';
import{ UserService } from '../../services/user.service';
import { Observable } from 'rxjs';
import { DataSource } from '@angular/cdk/collections';
import { User } from '../../models/user.model';
@Component({
  selector: 'usertable',
  templateUrl: './usertable.component.html',
  styleUrls: ['./usertable.component.css']
})
export class UsertableComponent implements OnInit {
dataSource  =new UserDataSource(this.userService);
displayedColumns =['_id','name','roll'];
  constructor(private userService:UserService) { }

  ngOnInit(): void {
  }


}
export class UserDataSource extends DataSource<any>{
  constructor (private userService: UserService){
    super();
  }
  connect(): Observable<User[]>{
    return this.userService.getUser();
  }
  disconnect() {}
}
