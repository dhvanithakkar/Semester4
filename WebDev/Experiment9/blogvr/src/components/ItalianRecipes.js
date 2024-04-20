function ItalianRecipes(){
  const recipes = [
    {
      id: 3,
      title: 'Ravioli Spinach Bake',
      date: 'March 14, 2022',
      image: require('./ravioli.jpeg'),
      description: 'This impressive ravioli is a perfect party dish and a fun meal to cook together with your guests. It is so easy you will be happy to make it any night of the week!',
      method: 'To make homemade ricotta and spinach ravioli, clean the spinach and boil them in a pot for about 10 minutes with only the water left over from washing. Drain and squeeze well with a fork or your hands to remove all the water.Finely chop the spinach with kitchen scissors or a knife. The ricotta must also be very dry. To remove the water, put the ricotta in a sieve for a few minutes. Finally, mix the ricotta with the spinach.Place them in a bowl and add the egg and grated Parmigiano Reggiano cheese.To finish, nutmeg to taste, salt and pepper. Mix until all the ingredients are combined.Transfer everything to a pastry bag without a nozzle. If you do not have a pastry bag, you can use a teaspoon. Set aside in the refrigerator for the time being - we are about to prepare the homemade pasta dough. Remember to flour the pasta sheet with semolina flour whenever you feel it is sticky. If the sheet of dough becomes too long, cut it in half.',
      comments: 30,
      likes:193,
      author: "Rajeev Thakkar",  
      authorId: 3
    },
    {
      id: 4,
      title: 'Pizza Margherita',
      date: 'March 15, 2022',
      image: require('./pizza.jpeg'),
      description: 'Here is the archetype of a thin-crust pizza pie, a pizza margherita adorned simply in the colors of the Italian flag: green from basil, white from mozzarella, red from tomato sauce.',
      method: 'Place a pizza stone or tiles on the middle rack of your oven and turn heat to its highest setting. Let it heat for at least an hour. Put the sauce in the center of the stretched dough and use the back of a spoon to spread it evenly across the surface, stopping approximately 1 inch from the edges.Drizzle a little olive oil over the pie. Break the cheese into large pieces and place these gently on the sauce. Scatter basil leaves over the top.Using a pizza peel, pick up the pie and slide it onto the heated stone or tiles in the oven. Bake until the crust is golden brown and the cheese is bubbling, approximately 4 to 8 minutes.',
      comments: 77,
      likes:266,
      author: "Hemangini Thakkar",  
      authorId: 2
    },
    {
        id:5,
        title: 'Tiramisu',
        date: 'December 13, 2022',
        image: require('./tiramisu.jpeg'),
        description: 'Tiramisu is an Italian dessert made of ladyfinger pastries dipped in coffee, layered with a whipped mixture of eggs, sugar and mascarpone and flavoured with cocoa. ',
        method: 'Whisk together mascarpone cheese, heavy cream, and sugar on high speed until soft peaks form. Whisk in the amaretto.Soak the ladyfingers.Assemble. Spread half of the mascarpone mixture over the ladyfingers and cover with half of the chocolate. Dip the remaining ladyfingers in espresso and arrange them in a single layer over the filling. Cover with the remaining mascarpone and chopped chocolate.Chill for 4-6 in the refrigerator.',
        comments: 43,
        likes:156,
        author: "Dhvani Thakkar",  
        authorId: 1
    }
  ];

  return recipes;
};

export default ItalianRecipes;
