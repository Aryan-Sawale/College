import React from "react";
import "./Story.css";

export default function Story({ img, username }) {
  return (
    <div className="storyCard">
      <img
        src={img}
        width="60px"
        height="60px"
        alt="story"
        className="storyImg"
      />
      <center>{username}</center>
    </div>
  );
}

// span is same as div but doesn't add newline
