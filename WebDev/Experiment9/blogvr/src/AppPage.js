
import './App.css';
import React, { useState } from 'react';
import ItalianRecipes from './components/ItalianRecipes.js';
import IndianRecipes from './components/IndianRecipes.js';
import MexicanRecipes from './components/MexicanRecipes.js';
import ThaiRecipes from './components/ThaiRecipes.js';
import Navbar from './components/Navbar.js';
import { GridCard } from './components/gridCard.js';

const AppPage = () =>{
  const [selectedCuisine, setSelectedCuisine] = useState('all');
  const [selectedSort, setSelectedSort] = useState("")
  let recipes = [];

  const handleSortChange = (sort) => {
    setSelectedSort(sort); //we get this easily
  }; //this goes to navbar now



  const handleCuisineChange = (cuisine) => {
    setSelectedCuisine(cuisine); //we get this easily
  }; //this goes to navbar now
  let selectedRecipesComponent;
switch (selectedCuisine) {
  case 'all':
    recipes = []
    const indian = IndianRecipes();
    const thai = ThaiRecipes();
    const italian = ItalianRecipes();
    const mexican = MexicanRecipes();
    
    recipes = indian.concat(thai, italian, mexican)
    break;
  case 'indian':
    recipes = []
    recipes = IndianRecipes();
    break;
  case 'thai':
    recipes = []
    recipes = ThaiRecipes();
    break;
  case 'italian':
    recipes = []
    recipes = ItalianRecipes();
    break;
  case 'mexican':
    recipes = []
    recipes = MexicanRecipes();
    break;
  default:
    recipes = [];
}

switch(selectedSort) {
  case "likes":
    recipes = recipes.sort(function(a,b) {return b.likes - a.likes});
    break;
  case "comments":
    recipes = recipes.sort(function(a,b) {return b.comments - a.comments});

    break;
  default:
}  

selectedRecipesComponent = <GridCard recipes = {recipes}></GridCard>;

return (
  <div className="App">
    <h2 className="Title">World of Recipes</h2>
    <Navbar selectedCuisine={selectedCuisine} onCuisineChange={handleCuisineChange} sort={selectedSort} onSortChange={handleSortChange} />
    {selectedRecipesComponent}

  </div>
);

}

export default AppPage;
