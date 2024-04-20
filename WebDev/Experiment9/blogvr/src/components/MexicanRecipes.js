function MexicanRecipes() {
  const recipes = [
    {
      id: 7,
      title: 'Tres Leches Cake',
      date: 'March 14, 2022',
      image: require('./tresleches.jpeg'),
      description: 'A tres leches cake, dulce de tres leches, also known as pan tres leches or simply tres leches, is a sponge cake soaked in three kinds of milk: evaporated milk, condensed milk, and whole milk.',
      method: 'To make a tres leches cake, start by preheating your oven to 350°F (175°C) and greasing a 9x13 inch baking dish. In a large mixing bowl, beat 4 eggs and 1 cup of sugar until light and fluffy, then add 1 teaspoon of vanilla extract. Sift in 1 cup of all-purpose flour and 1 1/2 teaspoons of baking powder, gently folding until just combined. Pour the batter into the prepared baking dish and bake for 25-30 minutes, or until a toothpick inserted into the center comes out clean. Once the cake is baked, allow it to cool for about 10 minutes, then poke holes all over the surface with a fork. In a separate bowl, mix together 1 can of evaporated milk, 1 can of sweetened condensed milk, and 1 cup of whole milk, then pour this mixture evenly over the cake, allowing it to soak in. Chill the cake in the refrigerator for at least 4 hours or overnight. Before serving, whip 1 cup of heavy cream with 2 tablespoons of sugar until stiff peaks form, then spread it over the top of the chilled cake. Enjoy your deliciously moist tres leches cake!',
      comments: 50,
      likes:123,
      author: "Hemangini Thakkar",  
      authorId: 2

    },
    {
      id: 8,
      title: 'Enchiladas',
      date: 'March 15, 2022',
      image: require('./enchiladas.jpeg'),
      description: 'Enchiladas are corn tortillas rolled around a filling, typically of meat or beans, covered in a chili sauce and cheese, then baked until it is bubbly.',
      method: 'To make enchiladas, start by preparing the filling: cook 1 pound of ground beef (or chicken or beans for a vegetarian option) with diced onions, garlic, and your choice of spices until browned. Warm corn tortillas in a skillet, then fill each with a spoonful of the cooked filling and a sprinkle of shredded cheese. Roll up the tortillas and place them seam-side down in a baking dish. In a separate saucepan, heat up your favorite enchilada sauce (either homemade or store-bought), then pour it over the rolled tortillas in the baking dish. Top with more shredded cheese and any additional toppings you like, such as sliced olives or diced jalapeños. Bake in a preheated oven at 350°F (175°C) for about 20 minutes, until the cheese is melted and bubbly. Serve hot with toppings like sour cream, diced tomatoes, and chopped cilantro. Enjoy your delicious homemade enchiladas!',
      comments: 40,
      likes:140,
      author: "Rajeev Thakkar", 
      authorId: 3 
    },
   
  ];

  return recipes;
};

export default MexicanRecipes;