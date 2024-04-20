function IndianRecipes(){
  const recipes = [
    {
      id: 1,
      title: 'Idlis',
      date: 'March 14, 2022',
      image: require('./idli.jpeg'),
      description: 'Idli is a traditional South Indian steamed rice and lentil cake, soft and fluffy in texture, typically served with sambar and coconut chutney for a delicious breakfast or snack.',
      method: 'To make idli, start by rinsing 1 cup of urad dal (black lentils) and 2 cups of idli rice (or parboiled rice) separately, then soaking them in water for at least 4 hours or overnight. Drain the water and grind the urad dal and rice separately into a smooth paste using a blender or wet grinder, adding a little water as needed. Combine the two ground pastes in a large bowl, along with 1 teaspoon of salt, and mix well. Cover the bowl and let the batter ferment in a warm place for about 8-12 hours or until it doubles in volume. Once fermented, grease idli molds with oil or ghee and pour the batter into each mold, filling them about three-fourths full. Steam the idlis in a steamer for 10-12 minutes until they are cooked through and a toothpick inserted into the center comes out clean. Allow the idlis to cool for a few minutes before removing them from the molds. Serve the idlis hot with sambar and coconut chutney for a delicious and nutritious meal.',
      comments: 24,
      likes:133,
      author: "Dhvani Thakkar",  
      authorId: 1
    },
    {
      id: 2,
      title: 'Rasgulla',
      date: 'March 15, 2022',
      image: require('./rasgulla.webp'),
      description: 'Rasgulla is a traditional Indian dessert made from soft, spongy cheese balls (chenna) boiled in sugar syrup, resulting in a sweet and juicy delicacy enjoyed across the country.',
      method: 'To make rasgulla, start by bringing a pot of water to a boil and adding 1 cup of sugar, stirring until dissolved to make the sugar syrup. In a separate pot, heat 4 cups of full-fat milk until it comes to a boil, then turn off the heat and slowly add 2 tablespoons of lemon juice or vinegar, stirring gently until the milk curdles. Let it sit for a few minutes, then strain the curdled milk through a cheesecloth to separate the whey from the cheese (chenna). Rinse the chenna under cold water to remove any acidic taste, then gather the cheesecloth and squeeze out excess water. Knead the chenna for about 5 minutes until it becomes smooth and soft. Divide the chenna into small balls and gently flatten them. Place the balls in the simmering sugar syrup, cover, and cook for about 20 minutes. Remove from heat and let them cool. Serve the rasgullas chilled, garnished with saffron strands or chopped nuts if desired. Enjoy the delectable sweetness of homemade rasgullas!',
      comments: 46,
      likes:240,     
      author: "Hemangini Thakkar",  
      authorId: 2

    },
   
  ];


  return recipes;
  //(
  //   // <GridCard recipes = {recipes}></GridCard>
  // );
};

export default IndianRecipes;