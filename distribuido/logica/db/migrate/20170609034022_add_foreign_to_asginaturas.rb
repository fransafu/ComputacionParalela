class AddForeignToAsginaturas < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :asignaturas, :departamentos, column: :departamento_id, primary_key: :id
  end
end
