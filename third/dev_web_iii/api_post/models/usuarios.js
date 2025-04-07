import mongoose, {Schema} from "mongoose";

const usuarioSchema = new Schema({
    username : String,
    email : String,
    password : String,
    name : String, 
    created_at : {
        type: Date,
        default: Date.now
    }
});

export const Usuario = mongoose.model("Usuario", usuarioSchema, "usuarios");

