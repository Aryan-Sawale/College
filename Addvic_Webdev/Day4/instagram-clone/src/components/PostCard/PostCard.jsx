import React from "react";
import "./PostCard.css";
import { BiDotsHorizontalRounded } from "react-icons/bi";
import { BiUserCircle } from "react-icons/bi";
import { AiOutlineHeart } from "react-icons/ai";
import { FiSend } from "react-icons/fi";
import { BsBookmark, BsChat, BsEmojiSmile } from "react-icons/bs";

export default function PostCard({
  likes,
  postImg,
  userName,
  profilePic,
  postCaption,
  commentCount,
  comUser1,
  comUser2,
  com1,
  com2,
  postTime,
}) {
  return (
    <div className="postCard">
      <div className="postCard__header">
        <div className="profilepic_name">
          {/* <BiUserCircle className="postIcon" /> */}
          <img
            src={profilePic}
            alt="profile pic"
            width="25px"
            height="25px"
            id="pp"
          />
          <span>{userName}</span>
        </div>

        <span>
          <BiDotsHorizontalRounded />
        </span>
      </div>

      <img src={postImg} width="100%" alt="post image" />

      <div className="postActions">
        <div>
          <AiOutlineHeart className="postIcon" />
          <BsChat className="postIcon" />
          <FiSend className="postIcon" />
        </div>
        <BsBookmark className="postIcon" />
      </div>

      <div className="postCard__content">
        <span>
          <b>{likes} likes</b>
        </span>

        <span>
          <b>{userName}</b> {postCaption}
        </span>

        <span className="lighterText">{commentCount}</span>

        <span>
          <b>{comUser1}</b> {com1}
        </span>

        <span>
          <b>{comUser2}</b> {com2}
        </span>

        <span className="lighterText">
          <small>{postTime}</small>
        </span>
      </div>

      <div className="postCard__commentArea">
        <BsEmojiSmile className="postIcon" />
        <input type="text" placeholder="Add a comment.." />
        <a href="#">Post</a>
      </div>
    </div>
  );
}
