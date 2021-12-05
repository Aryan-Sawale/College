import React from "react";
import "./Home.css";
import { Link } from "react-router-dom";

const Home = () => {
  return (
    <div className="homePage">
      <h1>Hello, you're on home page</h1>
      <Link to="/User" id="linkButton">
        Go to Users
      </Link>
    </div>
  );
};

export default Home;
