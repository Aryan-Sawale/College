import React from "react";
import "./UserCard.css";

const UserCard = ( {Name, URL} ) => {
    return(
        <div className="box"> 
            <div>
                <img id="dp" src={URL} width="150px" alt="user profile" />
            </div>

            <div>
                <h1>First name: {Name}</h1>
                <h1>Course: BE</h1>
                <h1>Role: Developer</h1>
            </div>
        </div>
    )
}

export default UserCard;