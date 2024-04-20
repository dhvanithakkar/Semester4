import React from 'react';
import './AuthorPage.css';
import authorIcon from "./authorIcon.png"
import { useParams } from 'react-router-dom';
import Navbar from '../Navbar';

export const AuthorPage = () => {
  const { authorId } = useParams(); // Get the author 
  
  const authors = [
    {
        authorId: 1,
        name: "Dhvani Thakkar",
        bio: "Student at DJSCE.",
        recipes: ["Idlis", "Tiramisu", "Massaman Curry"],
        liked: 6,
        commented: 3
      },
      {
        authorId: 2,
        name: "Hemangini Thakkar",
        bio: "CISO, HSBC AMC India.",
        recipes: ["Rasgulla", "Pizza Margharita", "Tres Leches Cake"],
        liked: 8,
        commented: 4
      },
      {
        authorId: 3,
        name: "Rajeev Thakkar",
        bio: "CIO, PPFAS Mutual Fund.",
        recipes: ["Enchiladas", "Ravioli Spinach Bake"],
        liked: 4,
        commented: 2
      }];
  const author = authors.find(author => author.authorId === parseInt(authorId));
  if (!author) {
    return <div>Author not found.</div>; // Handle invalid author ID
  }
  const selectedCuisine ='all';
  const selectedSort = ""


  return (
    <div className='AuthorPage'>
        <h2 className="Title">World of Recipes</h2>
        <Navbar selectedCuisine={selectedCuisine} sort={selectedSort} />
        <div className="cardProfile">
        <img src={authorIcon} className="App-logo" alt="author" width={200}/>            
        <h2 className='authorName'>{author.name}</h2>
            
            <p className='authorBio'>{author.bio}</p>
            <p className='recipes'><h3>Recipes by {author.name}:</h3>
            <ul>
                {author.recipes.map(recipe => (
                <li key={recipe}>{recipe}</li>
                ))}
            </ul>
            </p>
            <p className='LikeComment'>
                <p><h4>Commented : </h4>{author.commented}</p>
                <p><h4>Liked : </h4>{author.liked}</p>

            </p>
        </div>
    </div>
  );
}

export default AuthorPage;
