import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { CommonModule } from '@angular/common';
import { Item } from "./item";
import { ItemComponent } from "./item/item.component";

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, CommonModule, ItemComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  componentTitle = "My To Do List";
  title = 'todolist';

  filter: "all" | "active" | "done" = "all";

  allItems = [
    { description: "eat", done: true },
    { description: "sleep", done: false },
    { description: "play", done: false },
    { description: "laugh", done: false },
  ];
  addItem(description: string) {
    if (!description) return;

    this.allItems.unshift({
      description,
      done: false
    });
  }
  remove(item: Item) {
    this.allItems.splice(this.allItems.indexOf(item), 1);
  }


  get items() {
    if (this.filter === "all") {
      return this.allItems;
    }
    return this.allItems.filter((item) =>
      this.filter === "done" ? item.done : !item.done
    );
  }
}
