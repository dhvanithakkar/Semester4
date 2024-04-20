
import './App.css';
import React, { useState, useCallback, useEffect } from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import ItalianRecipes from './components/ItalianRecipes.js';
import IndianRecipes from './components/IndianRecipes.js';
import MexicanRecipes from './components/MexicanRecipes.js';
import ThaiRecipes from './components/ThaiRecipes.js';
import Navbar from './components/Navbar.js';
import { Grid } from '@mui/material';




const App = () =>{
  const [selectedCuisine, setSelectedCuisine] = useState('all');
  const [selectedSort, setSelectedSort] = useState("")
  const [posts, setPosts]= useState("")
  let selectedRecipesComponent;
  const swap = useCallback((recipes, leftIndex, rightIndex) => {
    var temp = recipes[leftIndex]
    recipes[leftIndex] = recipes[rightIndex]
    recipes[rightIndex] = temp
  }, [])      

  const bubblesort = useCallback(
    (items) => {
      let i = 0;
      while (i < items.length) {
        let j = 0;
        while (j < items.length - i - 1) {
          if (items[j][selectedsort] > items[j+1][selectedsort]) {
            swap(items, j, j+1) //swap two elements
          }
          j++;
        }
        i++;
      }
    },
    [swap, selectedSort])
    // const fetchPost = useCallback(() => {
    //   // let data = posts
  
    //   // let result = bubblesort(data, 0, data.length - 1)
  
    //   // data = result.reverse().slice(0, 10)
    //   // // console.log(data)
    //   // setPosts([...data])
    // }, [bubblesort])
  
    // useEffect(() => {
    //   fetchPost()
    // }, [fetchPost, selectedSort])
  
  const handleSortChange = (sort) => {
    setSelectedSort(sort); //we get this easily
  }; //this goes to navbar now

  switch(selectedSort) {
    case "likes":
      break;
    case "comments":
      break;
    default:
  }

  
  const handleCuisineChange = (cuisine) => {
    setSelectedCuisine(cuisine); //we get this easily
  }; //this goes to navbar now
switch (selectedCuisine) {
  case 'all':
    // selectedRecipesComponent = <div><ItalianRecipes /><IndianRecipes /><MexicanRecipes /><ThaiRecipes /></div>;
    // setPosts(MexicanRecipes())
    break;
  case 'indian':
    setPosts(IndianRecipes())
    selectedRecipesComponent = () => 
    return (
        <Grid container spacing={3} padding={3}>
          {recipes.map(recipe => (
            <Grid item xs={12} sm={6} md={4} lg={3} key={recipe.id}>
              <RecipeCard recipe={recipe} />
            </Grid>
          ))}
        </Grid>
      );    
    

    break;
  case 'thai':
    selectedRecipesComponent = <ThaiRecipes />;
    break;
  case 'italian':
    selectedRecipesComponent = <ItalianRecipes />;
    break;
  case 'mexican':
    selectedRecipesComponent = <MexicanRecipes />;
    break;
  default:
    selectedRecipesComponent = null;
}

return (
  <Router>
  <div className="App">
    <h2 className="Title">World of Recipes</h2>
    <Navbar selectedCuisine={selectedCuisine} onCuisineChange={() => handleCuisineChange()} sort={selectedSort} onSortChange={() => handleSortChange()} />
    {selectedRecipesComponent}
  </div>
  </Router>
);

}

export default App;
