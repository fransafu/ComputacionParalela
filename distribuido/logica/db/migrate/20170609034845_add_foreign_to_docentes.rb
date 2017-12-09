class AddForeignToDocentes < ActiveRecord::Migration[5.0]
  def change
    add_foreign_key :docentes, :departamentos, column: :departamento_id, primary_key: :id
  end
end
