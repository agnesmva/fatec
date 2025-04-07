import mongoose, {mongo, Schema} from "mongoose";
import { Usuario } from "./usuarios.js";

const postagemSchema = new Schema({
    title : String,
    conten : String,
    author : Usuario.usuarioSchema,
    likes : {
        type: Number,
        default: 0
    },
    tags : [String],
    created_at : {
        type: Date,
        default: Date.now
    }
})

export const Postagem = mongoose.model("Postagem", postagemSchema, "postagens" )