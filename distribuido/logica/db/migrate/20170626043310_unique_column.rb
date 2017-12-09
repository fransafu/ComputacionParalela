class UniqueColumn < ActiveRecord::Migration[5.0]
  def change
    add_index :departamentos, :nombre, unique: true
    add_index :asignaturas, :codigo, unique: true
    add_index :cursos, :codigo, unique: true
  end
end
