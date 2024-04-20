
import './App.css';
import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import AuthorPage from './components/authors/authorPage.js';
import AppPage from './AppPage.js';

const App = () =>{
return (
  <Router>
    <Routes>
    <Route path = "/"element={<AppPage/>} ></Route>
    <Route path="/author/:authorId" element={<AuthorPage/>} />
  </Routes>

  </Router>
);

}

export default App;
