import React from "react";
import {Link} from "react-router-dom"

const Home = () => {
    return(
        <div>
            <h1>Hello, you're on home page</h1>
            <Link to="/User">Go to Users</Link>
        </div>
    )
}

export default Home