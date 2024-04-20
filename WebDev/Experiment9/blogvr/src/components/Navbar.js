import './NavBar.css';
import React from 'react';
// import Button from '@mui/material';
// import Typography from '@mui/material';
import { Link } from 'react-router-dom';


const Navbar = ({ selectedCuisine, onCuisineChange, sort, onSortChange }) => {

  return (
    <nav className="NavBar">
      <div className='Left_buttons'>
        <button
        className="left_button"
        variant={sort === 'likes' ? 'contained' : 'text'}
        color="primary" onClick={() => onSortChange('likes')}>
        Likes</button>
        <button
        className="left_button_comment"
        variant={sort === 'comments' ? 'contained' : 'text'} 
        color="primary" onClick={() => onSortChange('comments')}>
            Comments
        </button>

      </div>
      <div className='Right_buttons'>
        <button
        className="nav_button"
        variant={selectedCuisine === 'all' ? 'contained' : 'text'}
        color="primary"
        onClick={() => onCuisineChange('all')}
      >
        All
      </button>
        <button
          className="nav_button"
          variant={selectedCuisine === 'italian' ? 'contained' : 'text'}
          color="primary"
          onClick={() => onCuisineChange('italian')}
        >
          Italian
        </button>
        <button
          className="nav_button"
          variant={selectedCuisine === 'mexican' ? 'contained' : 'text'}
          color="primary"
          onClick={() => onCuisineChange('mexican')}
        >
          Mexican
        </button>
        <button
          className="nav_button"
          variant={selectedCuisine === 'indian' ? 'contained' : 'text'}
          color="primary"
          onClick={() => onCuisineChange('indian')}
        >
          Indian
        </button>
        <button
          className="nav_button"
          variant={selectedCuisine === 'thai' ? 'contained' : 'text'}
          color="primary"
          onClick={() => onCuisineChange('thai')}
        >
          Thai
        </button>
        <Link to={`/`} ><button className="all_recipes">Go to Recipes</button></Link>

      </div>
    </nav>
  );
};

export default Navbar;
