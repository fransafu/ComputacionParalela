class ModifacionSalasRemoveLatituLongitudRenameCapacidad < ActiveRecord::Migration[5.0]
  def change
    rename_column :salas, :capcidad ,:capacidad
    remove_column :salas, :latitud
    remove_column :salas , :longitud
  end
end
