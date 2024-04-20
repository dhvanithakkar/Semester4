import React from 'react';
import RecipeCard from "./RecipeCard";
import { Grid } from "@mui/material";

export const GridCard = ({recipes}) => {
    return (
    <Grid container spacing={3} padding={3}>
      {recipes.map(recipe => (
        <Grid item xs={12} sm={6} md={4} lg={3} key={recipe.id}>
          <RecipeCard recipe={recipe} />
        </Grid>
      ))}
    </Grid>
  );
};
