import React from "react";
import "./MainArea.css";

import Story from "../Story/Story";

import story1 from "../../assets/stories/story1.jpg";
import story2 from "../../assets/stories/story2.jpg";
import story3 from "../../assets/stories/story3.jpg";
import story4 from "../../assets/stories/story4.jpg";
import story5 from "../../assets/stories/story5.jpg";
import story6 from "../../assets/stories/story6.jpg";
import story7 from "../../assets/stories/story7.jpg";

import PostCard from "../PostCard/PostCard";
import postData from "../../postData";

export default function MainArea() {
  return (
    <div className="mainArea">
      <div className="storyArea">
        <Story img={story1} username="Shreya" />
        <Story img={story2} username="Aryan" />
        <Story img={story3} username="Neha" />
        <Story img={story4} username="Nakul" />
        <Story img={story5} username="Sahil" />
        <Story img={story6} username="Anuja" />
        <Story img={story7} username="Sarthak" />
      </div>
      <div className="postsArea">
        {postData.map((p, index) => {
          return (
            <PostCard
              key={index}
              userName={p.username}
              postImg={p.post}
              likes={p.likes}
              profilePic={p.dp}
              postCaption={p.caption}
              commentCount={p.comCount}
              comUser1={p.comUser1}
              com1={p.com1}
              comUser2={p.comUser2}
              com2={p.com2}
              postTime={p.postTime}
            />
          );
        })}
      </div>
    </div>
  );
}
